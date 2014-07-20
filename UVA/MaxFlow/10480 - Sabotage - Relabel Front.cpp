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
int e[N+5],h[N+5];
vector<int> L[N+5];
int n,m,x,y,z;
void maxFlow(){
    memset(h,0,sizeof(int)*n);
    memset(e,0,sizeof(int)*n);
    h[S]=n-1;
    for(int i=0;i<L[S].size();++i){
        int to=L[S][i];
        e[to]+=c[S][to];
        //e[S]-=c[S][to];
        c[to][S]+=c[S][to];
        c[S][to]=0;
        }
    queue<int> Q;
    memset(used,false,sizeof(bool)*n);
    for(int i=0;i<L[S].size();++i){
        int to=L[S][i];
        if(to==T)continue;
        Q.push(to);
        used[to]=true;
        }

    while(!Q.empty()){
        int u=Q.front();
        int m=-1;
        for(int i=0;i<L[u].size() && e[u]>0;++i){
            int to=L[u][i];
            if(c[u][to]>0){
                if(h[u]==1+h[to]){
                    int f=min(c[u][to],e[u]);
                    c[u][to]-=f;
                    c[to][u]+=f;
                    e[u]-=f;
                    e[to]+=f;
                    if(used[to])continue;
                    if(to==S || to==T)continue;
                    Q.push(to);
                    used[to]=true;
                    }
                else if(m==-1)m=h[to];
                else m=min(m,h[to]);
                }
            }
        if(e[u]>0)h[u]=1+m;
        else used[u]=false,Q.pop();
        }
    }

bool bfs(){
    queue<int> Q;
    Q.push(S);
    used[S]=true;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(used[to])continue;
            if(c[u][to]==0)continue;
            used[to]=true;
            Q.push(to);
            }
        }
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&z),L[--x].push_back(--y),L[y].push_back(x),c[x][y]=z,c[y][x]=z;
    maxFlow();
    memset(used,false,sizeof(bool)*n);
    bfs();
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
