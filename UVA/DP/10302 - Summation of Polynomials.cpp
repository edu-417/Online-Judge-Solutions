#include<cstdio>

long long n;
bool doit(){
    if(scanf("%lld",&n)!=1)return false;
    long long ans=n*(n+1)/2;
    ans*=ans;
    printf("%lld\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
