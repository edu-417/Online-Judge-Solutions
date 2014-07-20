#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
#define N 50
map<int,int> M;
vector< vector <int> > d;
vector< bool> used;
vector<int> L[N];
int m,n,ttl,caso=0,x,y;
bool doit(){
    scanf("%d",&m);
    if(m==0)return false;
    M.clear();
    for(int i=0;i<n;++i)L[i].clear();
    n=0;
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        if(M.find(x)==M.end())M[x]=n++;
        if(M.find(y)==M.end())M[y]=n++;
        L[M[x]].push_back(M[y]);
        L[M[y]].push_back(M[x]);
        }
    d.clear();
    d.resize(n,vector<int> (n,-1));
    queue<int> Q;
    for(int i=0;i<n;++i){
        used.clear();
        used.resize(n,false);
        d[i][i]=0;
        used[i]=true;
        Q.push(i);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(size_t j=0;j<L[u].size();++j){
                int to=L[u][j];
                if(used[to])continue;
                used[to]=true;
                d[i][to]=d[i][u]+1;
                Q.push(to);
                }
            }
        }
    while(1){
        scanf("%d%d",&x,&ttl);
        if(x==0 && ttl==0)break;
        int ans=0;
        for(int i=0;i<n;++i)if(d[ M[x] ][i]==-1 || d[ M[x] ][i]>ttl)++ans;
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++caso,ans,x,ttl);
        }
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
