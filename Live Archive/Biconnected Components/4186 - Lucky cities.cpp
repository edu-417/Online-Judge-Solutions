#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define N 100005
int low[N],d[N];
bool used[N],used2[N],cutP[N];
vector<int> L[N];
bool a[N];
struct edge{
    int x,y;
    edge(){}
    edge(int _x,int _y){
        x=_x;
        y=_y;
        }
    };
vector< vector<edge> > Bcc;
vector<edge> E;
set<int> S;
int C,n,m,x,y,timer;
void dfs(int u,int p=-1){
    used[u]=true;
    low[u]=d[u]=timer++;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(used[to]){
            if(to==p || used2[to])continue;
            E.push_back(edge(u,to));
            low[u]=min(low[u],d[to]);
            }
        else{
            E.push_back(edge(u,to));
            dfs(to,u);
            low[u]=min(low[u],low[to]);
            if(low[to]>=d[u]){
                if(p!=-1)cutP[u]=true;
                vector<edge> b;
                while(1){
                    edge e=E.back();
                    b.push_back(e);
                    E.pop_back();
                    if(e.x==u && e.y==to)break;
                    }
                Bcc.push_back(b);
                }
            }
        }
    used2[u]=true;
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    memset(used,false,sizeof(bool)*n);
    memset(used2,false,sizeof(bool)*n);
    Bcc.clear();
    timer=0;
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    int ans=0;
    for(int i=0;i<Bcc.size();++i){
        S.clear();
        for(int j=0;j<Bcc[i].size();++j){
            edge to=Bcc[i][j];
            S.insert(to.x);
            S.insert(to.y);
            }
        int l=(int)S.size();
        }
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
