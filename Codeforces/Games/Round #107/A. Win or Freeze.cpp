#include<cstdio>
#include<cstring>
#include<cmath>
#define N 10000000
int dp[N+5];
long long n;
bool f(long long x){
    if(x<=(long long)sqrt(n))if(dp[x]!=-1)return dp[x];
    bool isPrime=true;
    for(long long i=2;i*i<=x;++i)
        if(x%i==0){
            isPrime=false;
            if( !f(i) ){
                if(x<=(long long)sqrt(n))return dp[x]=true;
                return true;
                }
            if( !f(x/i) ){
                if(x<=(long long)sqrt(n))return dp[x]=true;
                return true;
                }
            }
    if(isPrime){
        if(x<=(long long)sqrt(n))return dp[x]=true;
        return true;
        }
    if(x<=(long long)sqrt(n))return dp[x]=false;
    return false;
    }
int main(){
    scanf("%I64d",&n);
    memset(dp,-1,sizeof(dp));
    bool ans=f(n);
    bool isPrime=true;
    long long move=0;
    for(long long i=2;i*i<=n;++i)
        if(n%i==0){
            isPrime=false;
            if(!f(i)){
                move=i;break;
                }
            if(!f(n/i)){
                move=n/i;break;
                }
            }
    if(isPrime)printf("1\n0\n");
    else if(ans)printf("1\n%I64d\n",move);
    else printf("2\n");
    }
