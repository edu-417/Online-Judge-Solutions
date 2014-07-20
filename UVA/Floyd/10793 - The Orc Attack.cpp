#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100
#define oo (1<<30)
int n,m,C,caso=0;
int d[N+5][N+5];

bool valid(int u){
    if(d[u][0]==oo)return false;
    for(int i=0;i<5;++i)if(d[u][i]!=d[u][0])return false;
    return true;
    }
void doit(){
    int x,y,z;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)d[i][j]=i==j?0:oo;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&x,&y,&z),--x,--y;
        z=min(z,d[x][y]);
        d[x][y]=z;
        d[y][x]=z;
        }
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if((long long)d[i][j]>(long long )d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];

    int ans=oo;
    for(int i=5;i<n;++i)
        if(valid(i)){
            int aux=0;
            for(int j=5;j<n;++j)aux=max(aux,d[i][j]);
            if(aux<oo)ans=min(ans,aux);
        }
    printf("Map %d: %d\n",++caso,ans<oo?ans:-1);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
