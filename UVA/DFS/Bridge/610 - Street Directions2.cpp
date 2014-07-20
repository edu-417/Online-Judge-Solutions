#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000
vector<pair<int,int> > Bridge,S;
vector<int> L[N+5];
bool used[N+5],used2[N+5];
int low[N+5],d[N+5];
int n,m,timer,x,y,caso;
void dfs(int u,int p=-1){
    if(used[u])return;
    used[u]=true;
    d[u]=low[u]=timer++;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        if(used[to]){
            low[u]=min(low[u],d[to]);
           if(!used2[to])S.push_back(make_pair(u,to));
            }
        else{
            S.push_back(make_pair(u,to));
            dfs(to,u);
            low[u]=min(low[u],low[to]);
            if(low[to]>d[u])Bridge.push_back(make_pair(u,to));
            }
        }
    used2[u]=true;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    Bridge.clear(),S.clear();
    memset(used,false,sizeof(bool)*n);
    memset(used2,false,sizeof(bool)*n);
    timer=0;
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    for(int i=0;i<n;++i)dfs(i);
    printf("%d\n\n",++caso);
    for(int i=0;i<S.size();++i)printf("%d %d\n",1+S[i].first,1+S[i].second);
    for(int i=0;i<Bridge.size();++i)printf("%d %d\n",1+Bridge[i].second,1+Bridge[i].first);
    printf("#\n");
    return true;
    }
    
int main(){
    caso=0;
    while(1)if(!doit())break;
    }
