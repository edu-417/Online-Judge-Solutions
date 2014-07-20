#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 1005
vector<int> L[N],LT[N];
vector<int> order;
int ct[N],dp[N],c[N];
bool used[N],in[N];
int n,m,C,x,y,scc;
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    }
bool dfs_scc(int u){
    if(used[u])return false;
    used[u]=true;
    c[u]=scc;
    for(int i=0;i<LT[u].size();++i){
        int to=LT[u][i];
        dfs_scc(to);
        }
    return true;
    }
int dfs2(int u){
    if(dp[u]!=-1)return dp[u];
    dp[u]=ct[u];
    for(int i=0;i<LT[u].size();++i){
        int to=LT[u][i];
        dp[u]=max(dp[u],ct[u]+dfs2(to));
        }
    return dp[u];
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear(),LT[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),LT[y].push_back(x);
    memset(used,false,sizeof(bool)*n);
    order.clear();
    for(int i=0;i<n;++i)dfs(i);
    memset(used,false,sizeof(bool)*n);
    scc=0;
    for(int i=n-1;i>=0;--i)scc+=dfs_scc(order[i]);
    memset(ct,0,sizeof(int)*scc);
    for(int i=0;i<n;++i)++ct[c[i]];
    memset(in,false,sizeof(bool)*scc);
    for(int i=0;i<scc;++i)LT[i].clear();
    for(int i=0;i<n;++i)
        for(int j=0;j<L[i].size();++j){
            int to=L[i][j];
            if(c[i]!=c[to])LT[c[i]].push_back(c[to]),in[c[to]]=true;
            }
    int ans=0;
    memset(dp,-1,sizeof(int)*scc);
    for(int i=0;i<scc;++i)
        if(!in[i])ans=max(ans,dfs2(i));
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
