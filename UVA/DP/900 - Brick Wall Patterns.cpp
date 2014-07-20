#include<cstdio>
#define N 50
long long dp[N+5];
int n;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    printf("%lld\n",dp[n]);
    return true;
    }
int main(){
    dp[0]=dp[1]=1;
    for(int i=2;i<=N;++i)dp[i]=dp[i-1]+dp[i-2];
    while(1)if(!doit())break;
    }
