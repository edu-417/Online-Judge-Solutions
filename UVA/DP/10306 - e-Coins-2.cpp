#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[305][305];
int n,S,C;
int x[45],y[45];
void doit(){
    scanf("%d%d",&n,&S);
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<=S;++i)
        for(int j=0;j<=S;++j)dp[i][j]=1<<30;
    dp[0][0]=0;
    for(int i=0;i<=S;++i)
        for(int j=0;j<=S;++j)
            for(int k=0;k<n;++k)
                if(x[k]<=i && y[k]<=j)dp[i][j]=min(dp[i][j],1+dp[i-x[k]][j-y[k]]);
    int ans=1<<30;
    for(int i=0;i<=S;++i){
        int j=(int)sqrt(S*S-i*i);
        if(i*i+j*j==S*S)ans=min(ans,dp[i][j]);
        }
    if(ans==1<<30)printf("not possible\n");
    else printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
