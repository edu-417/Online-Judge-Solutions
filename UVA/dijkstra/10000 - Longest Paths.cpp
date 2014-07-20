#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,s,caso;
vector<vector<int> > L;
vector<int> order;
vector<bool> used;
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    }
bool dagPath(){
    order.clear();
    used.clear();
    used.resize(n,false);
    for(int i=0;i<n;++i)dfs(i);

    vector<int> d(n,-n);
    d[s]=0;
    for(int i=0;i<n;++i){
        int u=order[n-1-i];
        for(int j=0;j<L[u].size();++j){
            int to=L[u][j];
            if(d[to]<d[u]+1)d[to]=d[u]+1;
            }
        }
    int ans=0;
    int pos=s;
    for(int i=0;i<n;++i)if(i==s)continue;
    else if(d[i]>ans)ans=d[i],pos=i;
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",++caso,s+1,ans,pos+1);
    printf("\n");
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    scanf("%d",&s);
    --s;
    L.clear();
    L.resize(n,vector<int> ());
    int x,y;
    while(1){
        scanf("%d%d",&x,&y);
        if(x==0 && y==0)break;
        L[--x].push_back(--y);
        }
    dagPath();
    return true;
    }
int main(){
    caso=0;
    while(1)if(!doit())break;
    }
