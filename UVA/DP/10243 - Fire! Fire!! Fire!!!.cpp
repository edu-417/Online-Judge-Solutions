#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000
vector<int> L[N+5];
bool used[N+5][2];
int dp[N+5][2];
int n,m,y;

int dfs(int u,bool b,int p=-1){
    if(used[u][b])return dp[u][b];
    used[u][b]=true;
    int ans=0;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        if(!b)ans+=1+dfs(to,true,u);
        else ans+=min(1+dfs(to,true,u),dfs(to,false,u));
        }
    return dp[u][b]=ans;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j)scanf("%d",&y),L[i].push_back(--y);
        }
    memset(used,false,sizeof(used));
    int ans=min(dfs(0,0),1+dfs(0,1));
    if(ans==0)++ans;
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
