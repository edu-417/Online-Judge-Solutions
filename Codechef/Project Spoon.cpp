#include<cstdio>

int C;
long long n;
long long dp[65];
long long c(int n,int k){
    long double ans=1;
    for(int i=0;i<k;++i)ans=ans*(n-i)/(i+1);
    return (long long)(ans+0.01);
    }

int f(){
    for(int i=2;i<=64;++i)if(dp[i]>=n)return i;
    return 65;
    }

void doit(){
    scanf("%lld",&n);
    printf("%d\n",f());
    }
int main(){
    for(int i=2;i<=64;++i)dp[i]=c(i,i/2);
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
