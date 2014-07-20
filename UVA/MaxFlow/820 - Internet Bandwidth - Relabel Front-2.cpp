#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define N 100
#define oo 1<<30
int n,m,x,y,z,S,T,caso=0;
vector<int> L[N+5];
int e[N+5], h[N+5];
int c[N+5][N+5];
bool used[N+5];
int maxFlow(){
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
    return e[T];
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
