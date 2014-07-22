#include<cstdio>
#include<queue>
#include<vector>
#define N 10005
using namespace std;
int n,x,y;
vector<int> L[N];

pair<int,int> bfs(int source){
    vector<bool> used(n,false);
    vector<int> d(n,-1);
    d[source]=0;
    used[source]=true;
    queue<int> Q;
    Q.push(source);
    int farthest=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(size_t i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(used[to])continue;
            used[to]=true;
            d[to]=d[u]+1;
            Q.push(to);
            farthest=to;
            }
        }
    return make_pair(farthest,d[farthest]);
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n-1;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    pair<int,int> b=bfs(0);
    printf("%d\n",bfs(b.first).second);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
