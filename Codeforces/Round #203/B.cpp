#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100000
int n,x;
int p[N+5],in[N+5],d[N+5];
bool type[N+5],used[N+5];
vector<int> L[N+5];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",type+i);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(x==0)continue;
        L[i].push_back(--x);
        in[x]++;
        }    
    for(int i=0;i<n;++i)d[i]=n;
    queue<int> Q;
    for(int i=0;i<n;++i)if(type[i]==1)Q.push(i),d[i]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(used[to])continue;
            if(in[to]>1)continue;
            d[to]=d[u]+1;
            p[to]=u;
            Q.push(to);
            }
        }    
    int u=n,ans=0;
    for(int i=0;i<n;++i)if(d[i]<n && d[i]>ans)ans=d[i],u=i;
    if(u==n){
        for(int i=0;i<n;++i)if(type[i]==1)u=i;
        }
    printf("%d\n",1+ans);
    for(int i=0;i<=ans;++i,u=p[u])printf("%s%d",i==0?"":" ",1+u);
    printf("\n");
    }
