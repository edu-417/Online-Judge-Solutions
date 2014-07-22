#include<cstdio>
#define N 30
int n;
int dp[N+5],g[N+5];
bool doit(){
    scanf("%d",&n);
    if(n==-1)return false;
    printf("%d\n",dp[n]);
    return true;
    }

void f(){
    dp[0]=1,dp[2]=3,g[1]=1;
    for(int i=1;i<=N;i+=2)dp[i]=0;
    for(int i=2;i<=N;i+=2)g[i]=0;
    for(int i=3;i<=N;++i){
        if(i&1)g[i]=dp[i-1]+g[i-2];
        else dp[i]=3*dp[i-2]+2*g[i-3];
        }
    }
int main(){
    f();
    int f2=dp[2];
    int f4=dp[4];
    int g1=g[1];
    int g3=g[3];
    int ans=f2*f4+g3*f2+g1*f4;
    printf("%d\n",ans);
    while(1)if(!doit())break;
    }
