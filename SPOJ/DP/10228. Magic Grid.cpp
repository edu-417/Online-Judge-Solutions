#include<cstdio>
#include<algorithm>
using namespace std;
#define N 500
int a[N+5][N+5];
int dp[N+5][N+5];
int n,m,C;

void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)scanf("%d",a[i]+j);
    
    dp[n-1][m-1]=1;
    for(int i=n-1;i>=0;--i)
        for(int j=m-1;j>=0;--j){
            if(i==n-1 && j==m-1)continue;
            int aux1=max(1,dp[i+1][j]-a[i+1][j]);
            int aux2=max(1,dp[i][j+1]-a[i][j+1]);
            if(i==n-1)dp[i][j]=aux2;
            else if(j==m-1)dp[i][j]=aux1;
            else dp[i][j]=min(aux1,aux2);
            }
    
    printf("%d\n",dp[0][0]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
