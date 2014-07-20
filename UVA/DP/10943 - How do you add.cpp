#include<cstdio>
#include<cstring>
#define mod 1000000
int n,k;
int dp[105];
bool doit(){
    scanf("%d%d",&n,&k);
    if(n==0 && k==0)return false;
    memset(dp,0,sizeof(int)*(n+1));
    // dp[n][k]=Sumatoria(dp[i][k-1]) i=0:n
    // dp[n][k]=dp[n][k-1]+Sumatoria(dp[i][k-1]) i=0:n-1
    // => dp[n][k]=dp[n][k-1]+dp[n-1][k]
    dp[0]=1;
    for(int j=1;j<=k;++j){
        for(int i=1;i<=n;++i)dp[i]+=dp[i-1],dp[i]%=mod;
        }
    printf("%d\n",dp[n]);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
