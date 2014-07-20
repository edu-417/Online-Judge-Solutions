#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 100
#define oo 1<<30
int n,m,S,T,x,y,z,caso=0;
vector<int> L[N+5];
bool used[N+5];
int c[N+5][N+5];
int dfs(int u,int fp){
    if(used[u])return 0;
    used[u]=true;
    if(u==T)return fp;
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
int maxFlow(){
    int flow=0;
    while(true){
        memset(used,false,sizeof(bool)*n);
        int f=dfs(S,oo);
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
