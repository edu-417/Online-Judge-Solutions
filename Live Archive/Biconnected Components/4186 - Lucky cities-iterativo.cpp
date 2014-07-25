#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100000
bool used[N+5],used2[N+5];
int parent[N+5],d[N+5],low[N+5],last[N+5];
vector<int> L[N+5];
vector< vector<pair<int,int> > > bcc;
int n,m,x,y,timer,C;
void dfs(int r){
    stack<int> S;
    stack<pair<int,int> > E;    
    used[r]=true;
    parent[r]=-1;
    d[r]=low[r]=timer++;
    S.push(r);
    while(!S.empty()){
        int u=S.top();
        for(int &i=last[u];i<L[u].size();++i){
            int to=L[u][i];
            if(to==parent[u])continue;
            if(used2[to])continue;
            if(used[to]){
                low[u]=min(low[u],d[to]);
                E.push(make_pair(u,to));
                }
            else{
                S.push(to);
                used[to]=true;
                parent[to]=u;
                d[to]=low[to]=timer++;
                E.push(make_pair(u,to));
                break;
                }
            }
        
        if(last[u]==L[u].size()){
            S.pop();
            used2[u]=true;
            if(u!=r){
                low[parent[u]]=min(low[parent[u]],low[u]);
                if(low[u]>=d[parent[u]]){
                    vector<pair<int,int> > b;
                    while(1){
                        pair<int,int> e=E.top();
                        b.push_back(e);
                        x=e.first,y=e.second;
                        E.pop();
                        if(x==parent[u] && y==u)break;
                        }
                    bcc.push_back(b);
                    }
                }
            }
        }
    }
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    memset(used,false,sizeof(bool)*n);
    memset(used2,false,sizeof(bool)*n);
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    
    for(int i=0;i<bcc.size();++i){
        for(int j=0;j<bcc[i].size();++j){
            int u=bcc[i][j].first,to=bcc[i][j].second;
            color[u]=color[to]=-1;
            G[u].clear();G[to].clear();
            }
        for(int j=0;j<bcc[i].size();++j){
            int u=bcc[i][j].first,to=bcc[i][j].second;
            G[u].push_back()
            }
        }
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
