#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1600
int n,C;

int dp[N+5];
int grundy(int n){
    if(dp[n]>-1)return dp[n];
    set<int> S;
    for(int i=0;i<n-2;++i)S.insert(grundy(i)^grundy(n-i-3));
    int ans=0;
    while(S.find(ans)!=S.end())++ans;
    return dp[n]=ans;
    }
void doit(){
    scanf("%d",&n);
    int ans=grundy(2*n);
    printf("%s\n",ans==0?"Y":"X");
    }
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
