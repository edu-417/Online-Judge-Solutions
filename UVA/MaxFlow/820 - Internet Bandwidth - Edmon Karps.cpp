#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define N 100
#define oo 1<<30
int n,m,x,y,z,S,T,caso=0;
vector<int> L[N+5];
bool used[N+5];
int c[N+5][N+5];
int parent[N+5];
int bfs(){
    memset(used,false,sizeof(bool)*n);
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
            used[to]=true;
            parent[to]=u;
            if(to==T){
                path=true;
                break;
                }
            Q.push(to);
            }
        }
    if(!path)return 0;
    int fp=oo;
    for(int to=T;parent[to]!=-1;to=parent[to])fp=min(fp,c[parent[to]][to]);
    for(int to=T;parent[to]!=-1;to=parent[to])c[parent[to]][to]-=fp,c[to][parent[to]]+=fp;
    return fp;
    }
int maxFlow(){
    int flow=0;
    while(true){
        int f=bfs();
        if(f==0)break;
        flow+=f;
        }
    return flow;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)memset(c[i],0,sizeof(int)*n);
    scanf("%d%d%d",&S,&T,&m),--S,--T;
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&z),L[--x].push_back(--y),L[y].push_back(x),c[x][y]+=z,c[y][x]+=z;
    int ans=maxFlow();
    printf("Network %d\nThe bandwidth is %d.\n\n",++caso,ans);
    return true;
    }
int main(){
    while(true)if(!doit())break;
    }
