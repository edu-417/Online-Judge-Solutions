#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
#define M 100000
#define MOD 1000000000
struct edge{
    int x,y,w;
    edge(){}
    edge(int _x,int _y,int _w){
        x=_x;y=_y;w=_w;
        }
    };

bool operator <(const edge &e1,const edge &e2){
    return e1.w<e2.w;
    }

edge e[M+5];
int n,m,x,y,w;
int c[N+5],p[N+5];
long long s[M+5];
int Find(int x){
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
    }
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    p[x]=y;
    c[y]+=c[x];
    }
    
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&w),e[i]=edge(--x,--y,w);
    sort(e,e+m);
    unsigned long long ans=0;
    for(int i=0;i<n;++i)p[i]=i,c[i]=1;
    s[0]=e[0].w;
    for(int i=1;i<m;++i)s[i]=s[i-1]+e[i].w;
    for(int i=m-1;i>=0;--i){
        if(Find(e[i].x)!=Find(e[i].y)){
            ans=(ans+(unsigned long long)c[Find(e[i].x)]*c[Find(e[i].y)]*s[i])%MOD;
            Union(e[i].x,e[i].y);
            }
        }
    
    printf("%d\n",(int)ans);
    }
