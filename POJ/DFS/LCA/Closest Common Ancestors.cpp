#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 900
bool root[N+5];
int up[N+5][15],d[N+5],f[N+5],cnt[N+5];
int timer,n,m,x,y,q,a,b,l;

vector<int> L[N+5];
int log2(int n){
    int ans=0;
    while( (1<<ans) <=n)++ans;
    return ans;
    }
void dfs(int u,int p){
    d[u]=timer++;
    up[u][0]=p;
    for(int i=1;i<=l;++i)up[u][i]=up[up[u][i-1]][i-1];
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to,u);
        }
    f[u]=timer++;
    }

bool ancestor(int u,int v){
    return d[u]<=d[v] && f[v]<=f[u];
    }
int lca(int u,int v){
    if(ancestor(u,v))return u;
    if(ancestor(v,u))return v;
    for(int i=l;i>=0;--i)if(!ancestor(up[u][i],v))u=up[u][i];
    return up[u][0];
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)L[i].clear();
    memset(root,true,sizeof(bool)*n);
    for(int i=0;i<n;++i){
        scanf("%d:(%d)",&x,&m);--x;
        for(int j=0;j<m;++j)scanf("%d",&y),L[x].push_back(--y),root[y]=false;
        }
    timer=0;
    l=log2(n);
    for(int i=0;i<n;++i)if(root[i]){
        dfs(i,i);
        break;
        }
    scanf("%d",&q);
    memset(cnt,0,sizeof(int)*n);
    for(int i=0;i<q;++i){
        scanf("%*1s%d %d)",&a,&b);cnt[lca(--a,--b)]++;
        }
    for(int i=0;i<n;++i)if(cnt[i]>0)printf("%d:%d\n",i+1,cnt[i]);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
