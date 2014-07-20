#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 1005
vector<int> L[N];
int n,m,timer,x,y,caso=0;
int low[N],d[N];
bool used[N],used2[N];
struct edge{
    int x,y;
    edge(){}
    edge(int _x,int _y){
        x=_x;
        y=_y;
        }
    };
vector<edge> bridge,S;
void dfs(int u,int p=-1){
    used[u]=true;
    d[u]=low[u]=timer++;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        if(used[to]){
            low[u]=min(low[u],d[to]);
            if(!used2[to])S.push_back(edge(u,to));
            }
        else{
            S.push_back(edge(u,to));
            dfs(to,u);
            low[u]=min(low[u],low[to]);
            if(low[to]>d[u])bridge.push_back(edge(u,to));
            }
        }
    used2[u]=true;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    memset(used,false,sizeof(bool)*n);
    memset(used2,false,sizeof(bool)*n);
    bridge.clear(),S.clear();
    timer=0;
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    printf("%d\n\n",++caso);
    for(int i=0;i<S.size();++i)printf("%d %d\n",S[i].x+1,S[i].y+1);
    for(int i=0;i<bridge.size();++i)printf("%d %d\n",bridge[i].y+1,bridge[i].x+1);
    printf("#\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
