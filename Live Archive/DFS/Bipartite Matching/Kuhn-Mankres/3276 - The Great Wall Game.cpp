#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 15
int n,caso;
bool s[N+5],t[N+5];
int mt[N+5];
int lx[N+5],ly[N+5];
int x[N+5],y[N+5];
int c[N+5][N+5];
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
    int delta=1<<30;
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

int cost(){
    int ans=0;
    for(int i=0;i<n;++i)ans+=c[mt[i]][i];
    return ans;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i),--x[i],--y[i];

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)c[i][j]=abs(x[i]-j)+abs(y[i]-j);
    kuhnMunkres();
    int ans=cost();
    
    for(int row=0;row<n;++row){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)c[i][j]=abs(x[i]-row)+abs(y[i]-j);
        kuhnMunkres();
        ans=min(ans,cost());
        }
    for(int col=0;col<n;++col){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)c[i][j]=abs(x[i]-j)+abs(y[i]-col);
        kuhnMunkres();
        ans=min(ans,cost());
        }
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)c[i][j]=abs(x[i]-j)+abs(y[i]-(n-1-j));
    kuhnMunkres();
    ans=min(ans,cost());
    
    printf("Board %d: %d moves required.\n\n",++caso,ans);
    return true;
    }
int main(){
    caso=0;
    while(1)if(!doit())break;
    }
