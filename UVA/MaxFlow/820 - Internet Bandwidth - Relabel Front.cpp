#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 100
#define oo 1<<30
int n,m,x,y,z,S,T,caso=0,sz;
vector<int> L[N+5];
int e[N+5], h[N+5],Q[N+5];
int c[N+5][N+5];
bool empty(){return sz==0;}
void clear(){sz=0;}
int maxFlow(){
    memset(h,0,sizeof(int)*n);
    memset(e,0,sizeof(int)*n);
    h[S]=n-1;
    for(int i=0;i<L[S].size();++i){
        int to=L[S][i];
        e[to]+=c[S][to];
        //e[s]-=c[S][to];
        c[to][S]+=c[S][to];
        c[S][to]=0;
        }
    sz=0;
    while(true){
        if(empty())
            for(int i=0;i<n;++i)
                if(i!=S && i!=T && e[i]>0){
                    if(!empty() && h[i]>h[Q[0]])clear();
                    if(empty() || h[i]==h[Q[0]])Q[sz++]=i;
                    }
        if(empty())break;
        while(!empty()){
            int u=Q[sz-1];
            bool pushed=false;
            for(int i=0;i<L[u].size() && e[u]>0;++i){
                int to=L[u][i];
                if(c[u][to]>0 && h[u]==1+h[to]){
                    pushed=true;
                    int f=min(c[u][to],e[u]);
                    c[u][to]-=f,c[to][u]+=f;
                    e[u]-=f;
                    e[to]+=f;
                    if(e[u]==0)--sz;
                    }
                }
            if(!pushed){
                h[u]=oo;
                for(int i=0;i<L[u].size();++i){
                    int to=L[u][i];
                    if(c[u][to]>0 && h[to]+1<h[u])h[u]=1+h[to];
                    }
                if(h[u]>h[Q[0]]){
                    clear();
                    break;
                    }
                }
            }
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
