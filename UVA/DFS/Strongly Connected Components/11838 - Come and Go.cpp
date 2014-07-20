#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 2005
bool used[N];
vector<int> L[N],LT[N];
vector<int> order;
int n,m,x,y,p;
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(used[to])continue;
        dfs(to);
        }
    order.push_back(u);
    }

bool dfs_scc(int u){
    if(used[u])return false;
    used[u]=true;
    for(int i=0;i<LT[u].size();++i){
        int to=LT[u][i];
        dfs_scc(to);
        }
    return true;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear(),LT[i].clear();
    memset(used,false,sizeof(bool)*n);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&x,&y,&p);
        L[--x].push_back(--y);
        LT[y].push_back(x);
        if(p==2)L[y].push_back(x),LT[x].push_back(y);
        }
    order.clear();
    for(int i=0;i<n;++i)dfs(i);
    int scc=0;
    memset(used,false,sizeof(bool)*n);
    for(int i=n-1;i>=0;--i)scc+=dfs_scc(order[i]);
    printf("%d\n",scc==1);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
