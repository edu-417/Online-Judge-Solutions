#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int n,m,p,r;
bool b[205][205];
int d[205][205];
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
int dis(int x,int y){
    return x*x +y*y;
    }
bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m && !b[x][y];
    }
int bfs(){
    for(int i=0;i<n;++i)memset(d[i],-1,sizeof(int)*m);
    queue <nodo> Q;
    d[0][0]=0;
    Q.push(nodo(0,0));
    while(!Q.empty()){
        nodo q=Q.front();
        int x=q.x,y=q.y;
        Q.pop();
        for(int i=0;i<4;++i){
            int u=x+dx[i],v=y+dy[i];
            if(!isValid(u,v))continue;
            if(d[u][v]!=-1)continue;
            d[u][v]=d[x][y]+1;
            Q.push(nodo(u,v));
            }
        }
    return d[n-1][m-1];
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)memset(b[i],false,sizeof(bool)*m);
    scanf("%d",&p);
    int x,y,L;
    for(int i=0;i<p;++i)scanf("%d%d",&x,&y),b[--x][--y]=true;
    scanf("%d",&r);
    for(int i=0;i<r;++i){
        scanf("%d%d%d",&x,&y,&L);
        --x,--y;
        L*=L;
        for(int j=0;j<n;++j)
            for(int k=0;k<m;++k)if(dis(x-j,y-k)<=L)b[j][k]=true;
        }
    int ans=bfs();
    if(ans==-1)printf("Impossible.\n");
    else printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
