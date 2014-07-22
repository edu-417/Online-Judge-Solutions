#include<cstdio>
#define N 50
bool dp[N+5][N+5];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            bool aux=true;
            for(int k=1;k<i;++k)aux&=(dp[i-k][j]^dp[k][j]);
            for(int k=1;k<j;++k)aux&=(dp[i][j-k]^dp[i][k]);
            dp[i][j]=!aux;
            }
    printf("%s\n",dp[n][m]?"[:=[first]":"[second]=:]");
    }
