#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 105
vector<int> L[N];
vector<int> topological;
int n,m,x,y;
bool used[N];
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(size_t i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    topological.push_back(u);
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    topological.clear();
    memset(used,false,sizeof(bool)*n);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y);
    for(int i=0;i<n;++i)dfs(i);
    for(size_t i=topological.size()-1;i>0;--i)printf("%d ",topological[i]+1);
    printf("%d\n",topological[0]+1);
    return true;
    }
int main(){
    while(1)if(!doit())break;    
    }
