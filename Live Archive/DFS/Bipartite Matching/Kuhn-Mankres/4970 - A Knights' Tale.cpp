#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 15
long long c[N+5][N+5];
long long startx[N+5],starty[N+5];
long long endx[N+5],endy[N+5];
int n,caso;
bool s[N+5],t[N+5];
int mt[N+5];
long long lx[N+5],ly[N+5];
long long moves(long long x,long long y){
    if(x==2 && y==2)return 4;
    if(x<y)swap(x,y);
    if(x==1 && y==0)return 3;
    long long ans=0;
    if(x>=y*2){
        ans=y;
        x-=y*2;
        ans+=((x+2)/3*2);
        return ans;
        }
    ans=x-y;
    x=y*2-x;
    ans+=(x-x/4*2);
    return ans;
    }

bool dfs(int u){
    if(s[u])return false;// no afecta parece :s
    s[u]=true;
    for(int i=0;i<n;++i)
        if(c[u][i]-lx[u]-ly[i]==0){//if(abs(c[u][i]-lx[u]-ly[i])<eps && !t[i])
            t[i]=true;
            if(mt[i]==-1 || dfs(mt[i])){
                mt[i]=u;
                return true;
                }
            }
    return false;
    }

void update(){
    long long delta=(1LL<<60);
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
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
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
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%lld%lld",startx+i,starty+i);
    for(int i=0;i<n;++i)scanf("%lld%lld",endx+i,endy+i);
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)c[i][j]=moves(abs((long long)startx[i]-endx[j]),abs((long long)starty[i]-endy[j]));
    
        
    kuhnMunkres();
    long long ans=0;
    for(int i=0;i<n;++i)ans+=c[mt[i]][i];
    printf("%d. %lld\n",++caso,ans);
    }

int main(){
    caso=0;
    while(1)if(!doit())break;
    }
