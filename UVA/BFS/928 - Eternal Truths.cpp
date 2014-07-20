#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
#define N 301
char c[N];
string s[N];
int d[N][N][4];
int sourceX,sourceY,sinkX,sinkY,n,m,C,u,v,ans;
bool val;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
struct nodo{
    int x,y,moves;
    nodo(){}
    nodo(int _x,int _y,int _moves){
        x=_x;
        y=_y;
        moves=_moves;
        }
    };
nodo q;
bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m && s[x][y]!='#';
    }
int bfs(){
    if(sourceX==sinkX && sourceY==sinkY)return 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)memset(d[i][j],-1,sizeof(int)*4);
    d[sourceX][sourceY][2]=0;
    queue<nodo> Q;
    Q.push(nodo(sourceX,sourceY,2));
    int x,y,moves;
    while(!Q.empty()){
        q=Q.front();
        Q.pop();
        x=q.x,y=q.y,moves=q.moves+1;
        if(moves==3)moves=0;
        for(int i=0;i<4;++i){
            u=x,v=y;
            val=true;
            for(int j=0;j<moves+1;++j){
                u+=dx[i],v+=dy[i];
                if(isValid(u,v))continue;
                val=false;
                break;
                }
            if(!val)continue;
            if(d[u][v][moves]!=-1)continue;
            d[u][v][moves]=d[x][y][q.moves]+1;
            if(u==sinkX && v==sinkY)return d[u][v][moves];
            Q.push(nodo(u,v,moves));
            }
        }
    return -1;
    }
    
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",c),s[i]=string(c);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(s[i][j]=='S')sourceX=i,sourceY=j;
            else if(s[i][j]=='E')sinkX=i,sinkY=j;
    ans=bfs();
    if(ans==-1)printf("NO\n");
    else printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
