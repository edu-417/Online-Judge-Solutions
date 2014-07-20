#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define min(a,b) (a)<(b)? a:b
#define MN 40
#define N 20
#define oo 1<<30
int S,T,caso=0,n,m,C;
int c[MN+5][MN+5];
int row[N+5],col[N+5],e[MN+5],h[MN+5];
bool used[MN+5];
vector<int> L[MN+5];

int maxFlow(){
    memset(h,0,sizeof(int)*(T+1));
    memset(e,0,sizeof(int)*(T+1));
    h[S]=T;
    for(int i=0;i<L[S].size();++i){
        int to=L[S][i];
        e[to]+=c[S][to];
        //e[S]-=c[S][to];
        c[to][S]+=c[S][to];
        c[S][to]=0;
        }
    queue<int> Q;
    memset(used,false,sizeof(bool)*(T+1));
    for(int i=0;i<L[S].size();++i){
        int to=L[S][i];
        if(to==T)continue;
        used[to]=true;
        Q.push(to);
        }
        
    while(!Q.empty()){
        int u=Q.front();
        int m=-1;
        for(int i=0;i<L[u].size() && e[u]>0;++i){
            int to=L[u][i];
            if(c[u][to]>0){
                if(h[u]==1+h[to]){
                    int f=min(e[u],c[u][to]);
                    c[u][to]-=f;
                    c[to][u]+=f;
                    e[u]-=f;
                    e[to]+=f;
                    if(used[to])continue;
                    if(to==S || to==T)continue;
                    Q.push(to);
                    used[to]=true;
                    }
                else if(m==-1)m=h[to];
                else m=min(m,h[to]);
                }
            }
        if(e[u]>0)h[u]=1+m;
        else Q.pop(),used[u]=false;
        }
    return e[T];
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",row+i);
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
    maxFlow();
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
