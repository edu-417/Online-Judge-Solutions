#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 10005
vector<int> L[N],LT[N];
vector<int> order;
bool used[N];
int c[N],in[N],e[N];
int n,m,x,y,C,caso=0,scc;
bool dfs(int u){
    if(used[u])return false;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    return true;
    }
bool dfs_scc(int u){
    if(used[u])return false;
    used[u]=true;
    c[u]=scc;
    e[scc]=u;
    for(int i=0;i<LT[u].size();++i){
        int to=LT[u][i];
        dfs_scc(to);
        }
    return true;
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear(),LT[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),LT[y].push_back(x);
    order.clear();
    memset(used,false,sizeof(bool)*n);
    for(int i=0;i<n;++i)dfs(i);
    scc=0;
    memset(used,false,sizeof(bool)*n);
    memset(in,0,sizeof(int)*n);
    for(int i=n-1;i>=0;--i)scc+=dfs_scc(order[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<L[i].size();++j)if(c[i]!=c[L[i][j]])++in[c[L[i][j]]];
    memset(used,false,sizeof(bool)*n);
    int ans=0;
    order.clear();
    for(int i=0;i<scc;++i)if(in[i]==0)ans+=dfs(e[i]);
    printf("Case %d: %d\n",++caso,ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
