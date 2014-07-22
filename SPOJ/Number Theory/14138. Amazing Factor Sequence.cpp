#include<cstdio>
#define N 1000000
long long dp[N+5];
int factor[N+5];
int C;
void criba(){
    for(int i=4;i<N;i+=2)factor[i]=2;
    for(int i=3;i<N;i+=2)
        if(factor[i]==0)for(long long j=(long long)i*i;j<N;j+=i)if(factor[i]==0)factor[j]=i;
    }
long long f(int n){
    int x=n;
    long long ans=1;
    for(;factor[x]>0;){
        int d=factor[x];
        long long p=d;
        while(x%d==0)p*=d,x/=d;
        ans*=((p-1)/(d-1));
        }
    if(x>1)ans*=(x+1);
    ans-=n;
    return ans;
    }
void doit(){
    int n;
    scanf("%d",&n);
    printf("%lld\n",dp[n]);
    }
int main(){
    criba();
    for(int i=2;i<N;++i)dp[i]=dp[i-1]+f(i);
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
