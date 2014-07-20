#include<cstdio>
#include<cstring>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define N 200
#define oo INT_MAX
int n,m,S,T,x,y;
int win[N+5],wout[N+5];
int c[N+5][N+5];
bool used[N+5];
vector<int> L[N+5];
int dfs(int u,int fp){
    if(u==T)return fp;
    if(used[u])return 0;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(c[u][to]==0)continue;
        int f=dfs(to,min(c[u][to],fp));
        if(f==0)continue;
        c[u][to]-=f;
        c[to][u]+=f;
        return f;
        }
    return 0;
    }

void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(c[u][to]==0)continue;
        dfs(to);
        }
    }
    
int maxFlow(){
    int flow=0;
    while(1){
        memset(used,false,sizeof(used));
        int f=dfs(S,oo);
        if(f==0)break;
        flow+=f;
        }
    return flow;
    }

void recoverCut(){
    int edgeCut=0;
    memset(used,false,sizeof(used));
    dfs(S);
    for(int i=0;i<2*n+2;++i)if(used[i])
        for(int j=0;j<L[i].size();++j){
            int to=L[i][j];
            if(used[to])continue;
            if(c[i][to]==0 && c[to][i]>0)++edgeCut;
            }
    printf("%d\n",edgeCut);
    for(int i=0;i<2*n+2;++i)if(used[i])
        for(int j=0;j<L[i].size();++j){
            int to=L[i][j];
            if(used[to])continue;
            if(c[i][to]==0 && c[to][i]>0)if(i==S)printf("%d -\n",to+1);
            else if(to==T)printf("%d +\n",i+1-n);
            }
    }

void addEdge(int u,int to,int w){
    L[u].push_back(to);c[u][to]=w;
    }
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    
    for(int i=0;i<2*n+2;++i)L[i].clear();
    memset(c,0,sizeof(c));
    S=2*n;T=S+1;
    for(int i=0;i<n;++i)scanf("%d",win+i);//+
    for(int i=0;i<n;++i)scanf("%d",wout+i);//-
    
    for(int i=0,j=n;i<n;++i,++j)addEdge(j,T,win[i]),addEdge(T,j,win[i]);
    for(int i=0;i<n;++i)addEdge(S,i,wout[i]),addEdge(i,S,wout[i]);
    
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        --x,--y;
        addEdge(x,y+n,oo);addEdge(y+n,x,oo);
        }
    
    for(int i=0;i<2*n+2;++i)sort(L[i].begin(),L[i].end());
    for(int i=0;i<2*n+2;++i)L[i].resize(unique(L[i].begin(),L[i].end())-L[i].begin());
    int ans=maxFlow();
    printf("%d\n",ans);
    recoverCut();
    return true;
    
    }
int main(){
    while(1)if(!doit())break;
    }
