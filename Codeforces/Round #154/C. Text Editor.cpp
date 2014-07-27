#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
#define N 100
#define M 100000
int a[N+5];
int startX,startY,endX,endY;
int d[N+5][M+5];
bool used[N+5][M+5];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
struct nodo{
    int x, y;
    nodo(){}
    nodo(int _x,int _y){
        x=_x,y=_y;
        }
    };
int bfs(){
    queue<nodo>Q;
    d[startX][startY]=0;
    used[startX][startY]=true;
    Q.push(nodo(startX,startY));
    while(!Q.empty()){
        nodo q=Q.front();
        Q.pop();
        int x=q.x,y=q.y;
        for(int i=0;i<4;++i){
            int u=x+dx[i];
            int v=y+dy[i];
            if(u<0)u=0;
            else if(u>n-1)u=n-1;
            if(v<0)v=0;
            else if(v>a[u])v=a[u];
            if(used[u][v])continue;
            used[u][v]=true;
            Q.push(nodo(u,v));
            d[u][v]=d[x][y]+1;
            if(u==endX && v==endY)return d[u][v];
            }
        }
    return d[endX][endY];
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    scanf("%d%d%d%d",&startX,&startY,&endX,&endY);
    --startX,--startY;
    --endX,--endY;
    printf("%d\n",bfs());
    }
