#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define S 0
#define T 1
#define N 50
#define oo 1<<30
bool used[N+5];
int c[N+5][N+5];
int parent[N+5];
vector<int> L[N+5];
int n,m,x,y,z;
int bfs(){
    queue<int> Q;
    Q.push(S);
    used[S]=true;
    parent[S]=-1;
    bool path=false;
    while(!Q.empty()){
        if(path)break;
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(used[to])continue;
            if(c[u][to]==0)continue;
            Q.push(to);
            used[to]=true;
            parent[to]=u;
            if(to==T){
                path=true;
                break;
                }
            }
        }
    if(!path)return 0;
    int fp=oo;
    for(int to=T;parent[to]!=-1;to=parent[to])fp=min(fp,c[parent[to]][to]);
    for(int to=T;parent[to]!=-1;to=parent[to])c[parent[to]][to]-=fp,c[to][parent[to]]+=fp;
    return fp;
    }
void maxFlow(){
    while(true){
        memset(used,false,sizeof(bool)*n);
        int f=bfs();
        if(f==0)break;
        }
    }
void dfs(int u){
    if(used[u])return ;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(c[u][to]==0)continue;
        dfs(to);
        }
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&z),L[--x].push_back(--y),L[y].push_back(x),c[x][y]=z,c[y][x]=z;
    maxFlow();
    memset(used,false,sizeof(bool)*n);
    dfs(S);
    for(int i=0;i<n;++i){
        if(!used[i])continue;
        for(int j=0;j<L[i].size();++j){
            int to=L[i][j];
            if(used[to])continue;
            if(c[i][to]==0 && c[to][i]>0)printf("%d %d\n",i+1,to+1);
            }
        }
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
