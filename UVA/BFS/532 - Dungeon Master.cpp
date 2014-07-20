#include<cstdio>
#include<string>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
#define N 35
int startX,startY,startZ,endX,endY,endZ,n,m,p,u,v,w;
int dx[]={-1,0,0,0,0,1};
int dy[]={0,-1,0,0,1,0};
int dz[]={0,0,-1,1,0,0};

int d[N][N][N];
bool used[N][N][N];
char c[N];
string s[N][N];
struct nodo{
    int x,y,z;
    nodo(){}
    nodo(int _x,int _y, int _z){
        x=_x;
        y=_y;
        z=_z;
        }
    };
bool isValid(int x,int y,int z){
    return x>=0 && x<n && y>=0 && y<m && z>=0 && z<p && s[x][y][z]!='#';
    }
int bfs(){
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)memset(d[i][j],-1,sizeof(int)*(p+1));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)memset(used[i][j],false,sizeof(bool)*(p+1));
    queue<nodo> Q;
    d[startX][startY][startZ]=0;
    used[startX][startY][startZ]=true;
    Q.push(nodo(startX,startY,startZ));
    int x,y,z;
    while(!Q.empty()){
        nodo q=Q.front();
        x=q.x,y=q.y,z=q.z;
        Q.pop();
        for(int i=0;i<6;++i){
            u=x+dx[i],v=y+dy[i],w=z+dz[i];
            if(!isValid(u,v,w))continue;
            if(used[u][v][w])continue;
            used[u][v][w]=true;
            d[u][v][w]=d[x][y][z]+1;
            Q.push(nodo(u,v,w));
            }
        }
    return d[endX][endY][endZ];
    }
bool doit(){
    scanf("%d%d%d",&n,&m,&p);
    if(n==0 && m==0 && p==0)return false;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)scanf("%s",c),s[i][j]=string(c);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            for(int k=0;k<p;++k)
                if(s[i][j][k]=='S')startX=i,startY=j,startZ=k;
                else if(s[i][j][k]=='E')endX=i,endY=j,endZ=k;
    int ans=bfs();
    if(ans==-1)printf("Trapped!\n");
    else printf("Escaped in %d minute(s).\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
