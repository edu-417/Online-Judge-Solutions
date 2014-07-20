#include<cstdio>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define N 50
#define M 256*256
char c[4],c1[4],c2[4];
vector<int> L[N];
int ind[M];
int C,n,m,q,size,caso=0;
int bfs(int source,int sink){
    queue<int> Q;
    vector<int> d(N,-1);
    vector<bool> used(N,false);
    used[source]=true;
    d[source]=0;
    Q.push(source);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(used[to])continue;
            used[to]=true;
            d[to]=d[u]+1;
            Q.push(to);
            }
        }
    return d[sink];
    }
int f(char *cad){
    return cad[0]*256+cad[1];
    }
void doit(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<N;++i)L[i].clear();
    for(int i=0;i<n;++i)scanf("%s",c),ind[f(c)]=i;
    for(int i=0;i<m;++i)scanf("%s%s",c1,c2),L[ ind[f(c1)] ].push_back( ind[f(c2)]),L[ ind[f(c2)] ].push_back( ind[f(c1)]);
    printf("\nDATA SET  %d\n\n",++caso);
    for(int i=0;i<q;++i){
        scanf("%d%s%s",&size,c1,c2);
        size*=100;
        int ans=bfs(ind[f(c1)],ind[f(c2)]);
        if(ans==-1)printf("NO SHIPMENT POSSIBLE\n");
        else printf("$%d\n",ans*size);
        }
    }
int main(){
    printf("SHIPPING ROUTES OUTPUT\n");
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    printf("\nEND OF OUTPUT\n");
    }
