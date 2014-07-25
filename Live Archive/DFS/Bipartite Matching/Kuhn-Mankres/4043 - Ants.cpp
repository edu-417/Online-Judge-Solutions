#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
using namespace std;
//struct Point
typedef complex<int> Point;
#define x real()
#define y imag()
//
#define eps 1e-9
#define N 100
double lx[N+5],ly[N+5];
double c[N+5][N+5];
bool s[N+5],t[N+5];
int mt[N+5];
Point ant[N+5],tree[N+5];
int n,_x,_y;
bool first;
double mod(Point A){
    return sqrt(A.x*A.x+A.y*A.y);
    }

bool dfs(int u){
    if(s[u])return false;// no afecta parece :s
    s[u]=true;
    for(int i=0;i<n;++i)
        if(abs(c[u][i]-lx[u]-ly[i])<eps){//if(abs(c[u][i]-lx[u]-ly[i])<eps && !t[i])
            t[i]=true;
            if(mt[i]==-1 || dfs(mt[i])){
                mt[i]=u;
                return true;
                }
            }
    return false;
    }

void update(){
    double delta=1e50;
    for(int i=0;i<n;++i)
        if(s[i])for(int j=0;j<n;++j)
            if(!t[j])delta=min(delta,c[i][j]-lx[i]-ly[j]);
    
    for(int i=0;i<n;++i){
        if(s[i])lx[i]+=delta;
        if(t[i])ly[i]-=delta;
        }
    }
void kuhnMunkres(){
    memset(mt,-1,sizeof(mt));
    for(int i=0;i<n;++i){
        while(1){
            memset(s,false,sizeof(s));
            memset(t,false,sizeof(t));
            if(dfs(i))break;
            else update();
            }
        }
    }
    
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&_x,&_y),ant[i]=Point(_x,_y);
    for(int i=0;i<n;++i)scanf("%d%d",&_x,&_y),tree[i]=Point(_x,_y);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)c[i][j]=mod(tree[i]-ant[j]);
    kuhnMunkres();
    if(first)first=false;
    else printf("\n");
    for(int i=0;i<n;++i)printf("%d\n",mt[i]+1);
    return true;
    }
int main(){
    first=true;
    while(1)if(!doit())break;
    }
