#include<cstdio>
#define max(a,b) (a)>(b)? (a):(b)
#define N 1000
#define W 30
int n,C,m,weight;
int p[N+5],w[N+5];
int dp[W+5];
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",p+i,w+i);
    for(int i=0;i<=W;++i)dp[i]=0;
    for(int i=n-1;i>=0;--i)
        for(int j=W;j>=w[i];--j)
            dp[j]=max(dp[j],p[i]+dp[j-w[i]]);

    scanf("%d",&m);
    int ans=0;
    for(int i=0;i<m;++i){
        scanf("%d",&weight);
        ans+=dp[weight];
        }
    printf("%d\n",ans);
    
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
