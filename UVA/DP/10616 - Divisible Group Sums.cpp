#include<cstdio>
#define N 200
#define D 20
#define M 10
long long dp[N+5][D+5][M+5];
int a[N+5];
int n,q,caso,d,m;
bool doit(){
    scanf("%d%d",&n,&q);
    if(n==0 && q==0)return false;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    printf("SET %d:\n",++caso);
    for(int i=0;i<=n;++i)
        for(int j=0;j<=D;++j)
            for(int k=0;k<=m;++k)dp[i][j][k]=0;
                
    dp[n][0][0]=1;
                    
    for(int l=1;l<=q;++l){
        scanf("%d%d",&d,&m);
        for(int i=n-1;i>=0;--i)
            for(int j=0;j<d;++j)
                for(int k=0;k<=M;++k){
                    dp[i][j][k]=dp[i+1][j][k];
                    if(k>0)dp[i][j][k]+=dp[i+1][(d+j+(a[i]%d))%d][k-1];
                    }
        printf("QUERY %d: %lld\n",l,dp[0][0][m]);
        }
    return true;
    }
int main(){
    caso=0;
    while(1)if(!doit())break;
    }
