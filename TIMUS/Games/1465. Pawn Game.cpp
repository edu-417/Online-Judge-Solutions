#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define N 1000
int dp[N+5];
int grundy(int n){
    if(dp[n]!=-1)return dp[n];
    set<int>s;
    if(n>=2)s.insert(grundy(n-2));
    for(int i=2;i<n;++i)s.insert(grundy(i-2)^grundy(n-i-1));
    int ans=0;
    while(s.count(ans))++ans;
    return dp[n]=ans;
    }
int main(){
    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    for(int i=0;i<=N;++i)if(grundy(i)==0)printf("%d\n",i);
    }
