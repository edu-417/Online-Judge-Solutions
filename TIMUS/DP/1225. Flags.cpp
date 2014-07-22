#include<cstdio>
#define N 45
unsigned int dp[N+5][3];
int n;
int main(){
    scanf("%d",&n);
    dp[n][0]=dp[n][2]=1;
    for(int i=n-1;i>=1;--i)
        for(int j=0;j<3;++j){
            dp[i][j]=0;
            if(j!=0)dp[i][j]+=dp[i+1][0];
            if(j!=1 && i<n-1)dp[i][j]+=dp[i+2][2-j];
            if(j!=2)dp[i][j]+=dp[i+1][2];
            }
    printf("%u\n",dp[1][0]+dp[1][2]);
    }
