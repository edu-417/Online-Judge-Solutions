#include<cstdio>
#include<vector>
using namespace std;
#define N 900
int S1,S2,C;
int dp[N+5][9*N+5];
int dig[N+5][9*N+5];
void doit(){
    scanf("%d%d",&S1,&S2);
    if(S1>900 || S2>8100 || dp[S1][S2]>100)printf("No solution\n");
    else{
        vector<int> num;
        for(int i=S1,j=S2,d=0;i>0 && j>0;i-=d,j-=d*d)
            d=dig[i][j],num.push_back(d);
        for(int i=0;i<num.size();++i)printf("%d",num[i]);
        printf("\n");
        }
    }
int main(){
    for(int i=0;i<=N;++i)
        for(int j=0;j<=9*N;++j)dp[i][j]=1000;
    dp[0][0]=0;
    for(int i=0;i<=N;++i)
        for(int j=0;j<=9*N;++j)
            for(int k=1;k<=9;++k)
                if(i>=k && j>=k*k)
                    if(dp[i][j]>1+dp[i-k][j-k*k])dp[i][j]=1+dp[i-k][j-k*k],dig[i][j]=k;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
