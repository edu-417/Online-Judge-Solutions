#include<cstdio>
#define S 2000
#define N 100
int a[N+5];
bool dp[N+5][S+5][2];
int caso,C,n;
int f(){
    for(int i=1;i<=sum;++i)dp[n][i]=false;
    dp[n][0]=true;
    for(int i=n-1;i>=0;--i)
        for(int j=a[i];j<=sum;++j)
            for(int k=0;k<2)dp[i][j][k]=dp[i+1][j-a[i]][k+(j==a[i])]||dp[i+1][j][k];
    int ans=0;
    for(int j=0;j<=sum/2;++j)
        for(int i=0;i<n;++i)if(dp[i][j][0])ans=j;
    return ans;
    }
void doit(){
    scanf("%d",&n);
    sum=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),sum+=a[i];
    int ans=f();
    printf("Case %d: %d\n",++caso,ans);
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
