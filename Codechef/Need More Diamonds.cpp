#include<cstdio>
#define N 2000
double dp[N+5][N+5];
int v[N+5];
int n,C;
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",v+i);
    for(int i=0;i<=n;++i)
        for(int j=i;j<=n;++j)dp[i][j]=0.0;
    for(int i=n-1;i>=0;--i)
        for(int j=i;j<n;++j){
            dp[i][j]=dp[i+1][j];
            if(i+1<=j)dp[i][j]+=dp[i][j-1];
            if( ((j-i)&1) == ((n-1)&1) )dp[i][j]+=v[i]+v[j];
            dp[i][j]*=0.5;
            }
    printf("%lf\n",dp[0][n-1]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
