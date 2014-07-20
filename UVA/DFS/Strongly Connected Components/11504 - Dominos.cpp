#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 100005
vector<int> L[N],LT[N];
vector<int> order;
bool used[N],in[N];
int c[N];
int scc,n,m,C,x,y;
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
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear(),LT[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),LT[y].push_back(x);
    memset(used,false,sizeof(bool)*n);
    order.clear();
    for(int i=0;i<n;++i)dfs(i);
    scc=0;
    memset(used,false,sizeof(bool)*n);
    for(int i=n-1;i>=0;--i)scc+=dfs_scc(order[i]);
    memset(in,false,sizeof(bool)*scc);
    for(int i=0;i<n;++i)
        for(int j=0;j<L[i].size();++j){
            int to=L[i][j];
            if(c[i]!=c[to])in[c[to]]=true;
            }
    int ans=0;
    for(int i=0;i<scc;++i)if(!in[i])++ans;
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
