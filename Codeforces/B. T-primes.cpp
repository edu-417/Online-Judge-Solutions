#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1000005
bool prime[N];
int ct=0;
int n;
long long x;
void criba(){
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(long long i=2;i<N;++i)
        if(prime[i]){
            for(long long j=i*i;j<N;j+=i)prime[j]=false;
            }
    }
int main(){
    criba();
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%I64d",&x);
        long long y=(long long)sqrt(x*1.0);
        if(y*y==x && prime[y])printf("YES\n");
        else printf("NO\n");
        }
    }
