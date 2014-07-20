#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 100
bool used[N+5];
vector<int> L[N+5];
vector<int> order;
int n,m,x,y;
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y);
    order.clear();
    memset(used,false,sizeof(bool)*n);
    for(int i=0;i<n;++i)dfs(i);
    for(int i=n-1;i>=0;--i)printf("%s%d",i==n-1?"":" ",order[i]+1);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
