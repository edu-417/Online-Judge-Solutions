#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000
vector<int> L[N+5];
int match,n,m,k,x,y;
bool s[N+5],t[N+5],used[N+5];
int mt[N+5];
bool dfs(int u){
    if(s[u])return false;
    s[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(t[to])continue;
        t[to]=true;
        if(mt[to]==-1 || dfs(mt[to])){
            mt[to]=u;
            return true;
            }
        }
    return false;
    }
void kuhn(){
    match=0;
    memset(mt,-1,sizeof(int)*m);
    for(int i=0;i<n;++i){
        memset(s,false,sizeof(bool)*n);
        memset(t,false,sizeof(bool)*m);
        if(dfs(i))++match;
        }
    }
    
bool doit(){
    scanf("%d%d%d",&n,&m,&k);
    if(n==0 && m==0 && k==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<k;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y);
    kuhn();
    memset(used,false,sizeof(bool)*n);
    memset(s,false,sizeof(bool)*n);
    memset(t,false,sizeof(bool)*m);
    for(int i=0;i<m;++i)if(mt[i]>-1)used[mt[i]]=true;
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    printf("%d",match);
    for(int i=0;i<n;++i)if(!s[i])printf(" r%d",i+1);
    for(int i=0;i<m;++i)if(t[i])printf(" c%d",i+1);
    printf("\n");
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
