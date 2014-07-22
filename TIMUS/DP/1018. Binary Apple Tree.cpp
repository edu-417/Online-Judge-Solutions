#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 105
#define oo 1<<30
vector<int> L[N],L2[N];
int c[N][N];
bool used[N];
int dp[N][N];
int n,q,x,y,z;
int f(int root,int b){
    if(b==0)return 0;
    int &ret=dp[root][b];
    if(ret<oo)return ret;
    ret=-oo;
    if(L2[root].size()==0)return ret;
    ret = max( ret , f( L2[root][0] , b-1 ) + c[ root ][ L2[root][0] ] );
    if(L2[root].size()==1)return ret;
    for(int i=0;i<=b-2;++i)
        ret = max( ret , f( L2[root][0] , i ) + f ( L2[root][1] , b-2-i )+c[ root ][ L2[root][0] ]+c[ root ][ L2[root][1] ] );
    ret = max( ret , f( L2[root][1] , b-1 ) + c[ root ][ L2[root][1] ] );
    return ret;
    }
void dfs(int u){
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(used[to])continue;
        L2[u].push_back(to);
        dfs(to);
        }
    }
bool doit(){
    if(scanf("%d%d",&n,&q)!=2)return false;
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)L2[i].clear();
    for(int i=0;i<n-1;++i)scanf("%d%d%d",&x,&y,&z),L[--x].push_back(--y),L[y].push_back(x),c[x][y]=c[y][x]=z;
    for(int i=0;i<n;++i)used[i]=false;
    dfs(0);
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)dp[i][j]=oo;
    int ans=f(0,q);
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
