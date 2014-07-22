#include<cstdio>
#include<cstring>
bool prime[105];
int main(){
    memset(prime,true,sizeof(prime));
prime[0]=prime[1]=false;
    for(int i=2;i*i<=48;++i)
        if(prime[i])for(int j=i*i;j<=48;j+=i)prime[j]=false;
    long long ans=1;
    for(int i=2;i<48;++i)if(prime[i])printf("%d\n",i),ans*=i;
    printf("%lld\n",ans);
    }
