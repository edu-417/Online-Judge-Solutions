#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
int n,caso=0;
int a[N+5],dp[N+5][N+5];
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    int s=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),s+=a[i];
    for(int i=0;i<n-1;++i)dp[i][i+1]=max(a[i],a[i+1]);
    for(int i=n-4;i>=0;--i)
        for(int j=i+3;j<n;++j){
            if(a[i+1]>=a[j])dp[i][j]=a[i]+dp[i+2][j];
            else dp[i][j]=a[i]+dp[i+1][j-1];
            if(a[i]>=a[j-1])dp[i][j]=max(dp[i][j],a[j]+dp[i+1][j-1]);
            else dp[i][j]=max(dp[i][j],a[j]+dp[i][j-2]);
            }
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++caso,2*dp[0][n-1]-s);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
