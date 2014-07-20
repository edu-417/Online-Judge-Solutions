#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define eps 1e-9
#define oo 1e50
#define N 20
double lx[N+5],ly[N+5];
double c[N+5][N+5];
bool s[N+5],t[N+5];
int n,m;
int mt[N+5];
void update(){
    double delta=oo;
    for(int i=0;i<m;++i)
        if(s[i])for(int j=0;j<m;++j)
            if(!t[j])delta=min(delta,c[i][j]-lx[i]-ly[j]);
    for(int i=0;i<m;++i){
        if(s[i])lx[i]+=delta;
        if(t[i])ly[i]-=delta;
        }
    }

bool dfs(int u){
    if(s[u])return false;
    s[u]=true;
    for(int i=0;i<m;++i)
        if(fabs(c[u][i]-lx[u]-ly[i])<eps && !t[i]){
            t[i]=true;
            if(mt[i]==-1 || dfs(mt[i])){
                mt[i]=u;
                return true;
                }
            }
    return false;
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
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)scanf("%lf",c[i]+j);
    kuhnMunkres();
    double ans=0.0;
    for(int i=0;i<m;++i)if(mt[i]!=-1)ans+=c[mt[i]][i];
    printf("%.2lf\n",ans/n+eps);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
