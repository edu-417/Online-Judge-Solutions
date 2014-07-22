#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

bool diagon[1005][1005];
double dp[1005][1005];
int n,m,d,x,y;
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    scanf("%d",&d);
    for(int i=0;i<d;++i)scanf("%d%d",&x,&y),diagon[x][y]=true;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)dp[i][j]=1000000.0;
    dp[n][m]=0.0;
    for(int i=n;i>=0;--i)
        for(int j=m;j>=0;--j){
            if(i<n)dp[i][j]=1+dp[i+1][j];
            if(j<m)dp[i][j]=min(dp[i][j],1+dp[i][j+1]);
            if(i<n && j<m && diagon[i+1][j+1])dp[i][j]=min(dp[i][j],sqrt(2.0)+dp[i+1][j+1]);
            }
    printf("%.0lf\n",100.0*dp[0][0]);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
