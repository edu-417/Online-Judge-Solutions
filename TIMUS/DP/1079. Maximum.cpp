#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int dp[N+5];
int n;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    printf("%d\n",dp[n]);
    return true;
    }
int main(){
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=N;++i)
        if(i&1)dp[i]=dp[i/2]+dp[i/2+1];
        else dp[i]=dp[i/2];
    for(int i=1;i<=N;++i)dp[i]=max(dp[i],dp[i-1]);
    while(1)if(!doit())break;
    }
