#include<cstdio>

int n;
int a[20];
long long C[200][200], dp[20][200];
long long mod=1000000007LL;
void comb(){
    for(int i=0;i<=n;i++)C[i][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
void doit(){
    scanf("%d",&n);
    for (int i=0;i<=9;i++) scanf("%d",a+i);
    dp[10][0]=1;
    comb();
    for(int d=9;d>0;--d)
        for(int i=n;i>=0;i--)
            for(int j=i-a[d];j>=0;j--)
                if (d>0)dp[d][i]+=(dp[d+1][j]*C[i][j]),dp[d][i]%=mod;
                
    for(int i=n;i>0;i--)
        for(int j=i-a[0];j>0;j--)dp[0][i]+=(dp[1][j]*C[i-1][j-1]),dp[0][i]%=mod;
            
    int ans=0;
    for (int i=0;i<=n;i++)ans+=dp[0][i];
    printf("%d\n",ans);
    }
int main(){
    doit();
    }
