#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000
#define K 20
#define oo (1<<30)
bool used[N+5];
int dpI[N+5][K+5],dp[N+5][K+5],dpI2[N+5][K+5];
int value[N+5];
vector<int> L[N+5];
int n,k,x,y;

int dfs(int u,int p=-1){    
    if(used[u])return 0;
    used[u]=true;
    int children=0;
    int ans=0;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        ans+=dfs(to,u);
        ++children;
        }
    for(int i=0;i<=children;++i)
        for(int j=0;j<=k;++j)dpI[i][j]=oo;
    dpI[children][0]=0;
    
    for(int i=children-1;i>=0;--i)
        for(int j=0;j<=k;++j){
            int aux=oo;
            for(int l=0;l<=j;++l)aux=min(aux,dpI[i+1][j-l]+dp[L[u][i]][l]);
            dpI[i][j]=aux;
            }
    
    for(int i=0;i<=k;++i){
        
        for(int j=0;j<=i;++j)dpI2[children][j]=dpI[0][i-j];
        
        for(int j=children-1;j>=0;--j)
            for(int l=0;l<=i && l<=j;++l)dpI2[j][l]=min(dpI2[j+1][l],dpI2[j+1][l+1]+value[L[u][j]]);
        dp[u][i]=dpI2[0][0];
        }
    return ans;
    }

bool doit(){
    if(scanf("%d%d",&n,&k)!=2)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)scanf("%d",value+i);
    for(int i=0;i<n-1;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    memset(used,false,sizeof(used));
    dfs(0);
    int ans=dp[0][k];
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
