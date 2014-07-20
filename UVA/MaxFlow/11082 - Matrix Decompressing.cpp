#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define min(a,b) (a)<(b)? a:b
#define MN 40
#define N 20
#define oo 1<<30
int S,T,caso=0,n,m,C;
int c[MN+5][MN+5];
int row[N+5],col[N+5];
bool used[MN+5];
vector<int> L[MN+5];
int dfs(int u,int fp){
    if(used[u])return 0;
    used[u]=true;
    if(u==T)return fp;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(c[u][to]==0)continue;
        int f=dfs(to,min(fp,c[u][to]));
        if(f==0)continue;
        c[u][to]-=f;
        c[to][u]+=f;
        return f;
        }
    return 0;
    }
int maxFlow(){
    int flow=0;
    while(true){
        memset(used,false,sizeof(bool)*(T+1));
        int f=dfs(S,oo);
        if(f==0)break;
        flow+=f;
        }
    return flow;
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",row+i);
    int total=row[n-1];
    for(int i=n-1;i>0;--i)row[i]-=row[i-1];
    for(int i=0;i<n;++i)row[i]-=m;
    for(int i=0;i<m;++i)scanf("%d",col+i);
    for(int i=m-1;i>0;--i)col[i]-=col[i-1];
    for(int i=0;i<m;++i)col[i]-=n;
    S=n+m,T=S+1;
    for(int i=0;i<=T;++i)L[i].clear();
    for(int i=0;i<n;++i)L[S].push_back(i),L[i].push_back(S),c[S][i]=row[i],c[i][S]=0;
    for(int i=n;i<n+m;++i)L[T].push_back(i),L[i].push_back(T),c[T][i]=0,c[i][T]=col[i-n];
    for(int i=0;i<n;++i)
        for(int j=n;j<n+m;++j)L[i].push_back(j),L[j].push_back(i),c[i][j]=19,c[j][i]=0;
    int flow=maxFlow();
    printf("Matrix %d\n",++caso);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)printf("%s%d ",j==0?"":" ",1+c[n+j][i]);
        printf("\n");
        }
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
