#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100000
vector<int> L[N+5];
int n,m,timer,x,y,C,caso;
int d[N+5],low[N+5];
bool used[N+5],used2[N+5];
void dfs(int u, int p=-1){
    if(used[u])return;
    used[u]=true;
    d[u]=low[u]=++timer;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        if(used[to])low[u]=min(low[u],d[to]);
        else{
            dfs(to,u);
            low[u]=min(low[u],low[to]);
            if(low[to]<=d[u])used2[u]=used2[to]=true;
            }
        }    
    }
int dfs2(int u){
    if(used2[u])return 0;
    used2[u]=true;
    int ans=1;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        ans+=dfs2(to);
        }
    return ans;
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear();
    memset(used,false,sizeof(bool)*n);
    memset(used2,false,sizeof(bool)*n);
    timer=0;
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);    
    for(int i=0;i<n;++i)dfs(i);
    long long ans=0;
    for(int i=0;i<n;++i){
        int e=dfs2(i);
        ans+=(((long long)e*(e-1))>>1);
        }
    printf("Case #%d: %lld\n",++caso,ans);
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
