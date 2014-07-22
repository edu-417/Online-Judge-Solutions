#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100
bool s[N+5],t[N+5],used[N+5];
int match,n;
int mt[N+5];
int b[N+5][N+5];
vector<int> L[N+5];
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
    memset(mt,-1,sizeof(mt));
    for(int i=0;i<n;++i){
        memset(s,false,sizeof(s));
        memset(t,false,sizeof(t));
        if(dfs(i))++match;
        }
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",b[i]+j);
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)if(i==j)continue;
            else b[i][j]=b[i][j] || (b[i][k] && b[k][j]);
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(b[i][j])L[i].push_back(j);
    kuhn();
    memset(used,false,sizeof(used));
    memset(s,false,sizeof(s));
    memset(t,false,sizeof(t));
    for(int i=0;i<n;++i)if(mt[i]>-1)used[mt[i]]=true;
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    printf("%d\n",n-match);
    bool first=true;
    memset(used,false,sizeof(used));
    for(int i=0;i<n;++i)if(!s[i])used[i]=true;
    for(int i=0;i<n;++i)if(t[i])used[i]=true;
    for(int i=0;i<n;++i)if(!used[i])printf("%s%d",first?"":" ",i+1),first=false;
    }
