#include<cstdio>
#include<cstring>
#define N 200000
int n;
bool used[N+5][2];
int a[N+5];
long long dp[N+5][2];
long long dfs(int u,bool stp3){
    if(u<=0 || u>n)return 0;
    if(used[u][stp3])return dp[u][stp3];
    dp[u][stp3]=-1;
    used[u][stp3]=true;
    if(stp3){
        long long aux=dfs(u-a[u],false);
        if(aux==-1)return -1;
        return dp[u][stp3]=aux+a[u];
        }
    long long aux=dfs(u+a[u],true);
    if(aux==-1)return -1;
    return dp[u][stp3]=aux+a[u];
    }
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;++i)scanf("%d",a+i);
    used[1][0]=true;dp[1][0]=-1;
    for(int i=1;i<n;++i){
        long long ans=dfs(1+i,true);
        printf("%I64d\n",ans==-1?-1:ans+i);
        }
    }
