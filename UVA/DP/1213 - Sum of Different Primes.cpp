#include<cstdio>
#include<cstring>
#define N 1120
bool prime[N+5];
int dp[N+5][20];
int primo[200];
int n,q,m;
void criba(){
    m=0;
    memset(prime,true,sizeof(bool)*(N+1));
    for(int i=2;i<=N;++i)
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i)prime[j]=false;
            primo[m++]=i;
            }
    }
bool doit(){
    scanf("%d%d",&n,&q);
    if(n==0 && q==0)return false;
    for(int i=0;i<=n;++i)memset(dp[i],0,sizeof(int)*(q+1));
    dp[0][0]=1;
    for(int i=0;i<m;++i)
        for(int j=n;j>=primo[i];--j)
            for(int k=q;k>0;--k)
                dp[j][k]+=dp[j-primo[i]][k-1];
    printf("%d\n",dp[n][q]);
    return true;
    }
int main(){
    criba();
    while(1)if(!doit())break;
    }
