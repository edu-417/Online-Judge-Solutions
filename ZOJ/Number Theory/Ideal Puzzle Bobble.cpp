#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000000
int mu[N+5];
int n,m,C,p;
void cribaMu(){
    mu[1]=1;
    for(int i=1;i<=N;++i)
        for(int j=2*i;j<=N;j+=i)mu[j]-=mu[i];
    }
bool doit(){
    if(scanf("%d%d%d",&n,&m,&p)!=3)return false;
    --m,--n,--p;
    long long ans=3;
    for(int i=1;i<=min(p,min(m,n));++i)ans+=((long long)mu[i]*(m/i)*(n/i)*(p/i));
    for(int i=1;i<=min(m,n);++i)ans+=((long long)mu[i]*(m/i)*(n/i));
    for(int i=1;i<=min(m,p);++i)ans+=((long long)mu[i]*(m/i)*(p/i));
    for(int i=1;i<=min(n,p);++i)ans+=((long long)mu[i]*(n/i)*(p/i));
    printf("%lld\n",ans);
    return true;
    }
int main(){
    cribaMu();
    while(1)if(!doit())break;
    }
