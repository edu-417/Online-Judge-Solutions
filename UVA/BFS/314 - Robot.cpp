#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 55
bool b[N][N],a[N][N];
char c[10];
int direccion[256];
int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
int n,m,startX,startY,endX,endY,newDir;
vector< vector<int> > d[4];
struct nodo{
    int x, y, dir;
    nodo(){}
    nodo(int _x,int _y,int _dir){
        x=_x;
        y=_y;
        dir=_dir;
        }
    };
bool isValid(int x,int y){
    return x>=0 && x<n-1 && y>=0 && y<m-1 && !b[x][y];
    }
int bfs(int sourceX,int sourceY,int dir){
    if(sourceX==endX && sourceY==endY)return 0;
    for(int i=0;i<4;++i)d[i]=vector< vector<int> > (n,vector<int> (m,-1));
    d[dir][sourceX][sourceY]=0;
    queue<nodo> Q;
    Q.push(nodo(sourceX,sourceY,dir));
    int x,y,direccion;
    while(!Q.empty()){
        nodo q=Q.front();
        Q.pop();
        x=q.x,y=q.y;
        direccion=q.dir;
        for(int i=-1;i<=1;i+=2){
            newDir=(4+direccion+i)%4;
            if(d[newDir][x][y]!=-1)continue;
            d[newDir][x][y]=d[direccion][x][y]+1;
            Q.push(nodo(x,y,newDir));
            }
        for(int i=1;i<4;++i){
            int u=x+i*dx[direccion],v=y+i*dy[direccion];
            if(!isValid(u,v))break;
            if(d[direccion][u][v]!=-1)continue;
            d[direccion][u][v]=d[direccion][x][y]+1;
            if(u==endX && v==endY)return d[direccion][u][v];
            Q.push(nodo(u,v,direccion));
            }
        }
    return -1;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)scanf("%d",a[i]+j);
    scanf("%d%d%d%d",&startX,&startY,&endX,&endY);
    --startX,--startY,--endX,--endY;
    scanf("%s",c);
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            b[i-1][j-1]=a[i][j] || a[i-1][j-1] || a[i-1][j] || a[i][j-1];
    int ans=bfs(startX,startY,direccion[c[0]]);
    printf("%d\n",ans);
    return true;
    }
int main(){
    direccion['w']=0;
    direccion['n']=1;
    direccion['e']=2;
    direccion['s']=3;
    while(1)if(!doit())break;
    }
