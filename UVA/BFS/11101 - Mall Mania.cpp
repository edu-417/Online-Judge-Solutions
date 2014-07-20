#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define N 2000
int n,x,y;
int d[N+5][N+5];
bool end[N+5][N+5];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
struct nodo{
    int x,y;
    nodo(){}
    nodo(int _x,int _y){
        x=_x;
        y=_y;
        }
    };

bool isValid(int x,int y){
    return x>=0 && x<=N && y>=0 && y<=N;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    memset(d,-1,sizeof(d));
    memset(end,false,sizeof(end));
    queue<nodo> Q;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),Q.push(nodo(x,y)),d[x][y]=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),end[x][y]=true;
    int ans=-1;
    while(!Q.empty()){
        nodo q=Q.front();Q.pop();
        int x=q.x,y=q.y;
        for(int i=0;i<4;++i){
            int u=x+dx[i],v=y+dy[i];
            if(!isValid(u,v))continue;
            if(d[u][v]!=-1)continue;
            d[u][v]=d[x][y]+1;
            if(end[u][v]){
                ans=d[u][v];
                break;
                }
            Q.push(nodo(u,v));
            }
        if(ans!=-1)break;
        }
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
