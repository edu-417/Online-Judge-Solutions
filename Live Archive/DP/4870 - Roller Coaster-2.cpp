#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
#define oo 1<<20
#define F 20
int f[N+5],d[N+5];
int n,k,L;
int dp[2][F*N+5];
int g(){
    for(int i=0;i<2;++i)
        for(int j=0;j<=F*n;++j)dp[i][j]=oo;
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=F*n;++j){
            int aux1=max(0,dp[(i-1)&1][j]-k);
            if(dp[(i-1)&1][j]>L)aux1=oo;
            if(j<f[i-1])dp[i&1][j]=aux1;
            else{
                int aux2=dp[(i-1)&1][j-f[i-1]]+d[i-1];
                if(aux2>L)aux2=oo;
                dp[i&1][j]=min(aux1,aux2);
                }
            }
    
    for(int i=F*n;i>=0;--i)if(dp[n&1][i]<=L)return i;
    return 0;
    }
bool doit(){
    scanf("%d%d%d",&n,&k,&L);
    if(n==0 && k==0 && L==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",f+i,d+i);
    int ans=g();
    printf("%d\n",ans);
    }
    
int main(){
    while(1)if(!doit())break;
    }
