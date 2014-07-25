#include<cstdio>
#define oo (1LL<<60)
#define N 1000
long long dp[N+5][N+5];
int a[N+5];
int root[N+5][N+5];
int l,n;
bool doit(){
    if(scanf("%d%d",&l,&n)!=2)return false;
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    a[0]=0;a[n+1]=l;    
    for(int L=0;L<=n;++L)dp[L][L+1]=0,root[L][L+1]=L;
    for(int s=2;s<=n+1;++s)
        for(int L=0;L+s<=n+1;++L){
            int R=L+s;
            long long ans=oo;
            for(int i=root[L][R-1];i<=root[L+1][R];++i){
                if(i==L || i==R)continue;
                int aux=dp[L][i]+dp[i][R]+a[R]-a[L];
                if(aux<ans)ans=aux,root[L][R]=i;
                }
            dp[L][R]=ans;
            }
    
    printf("%lld\n",dp[0][n+1]);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
