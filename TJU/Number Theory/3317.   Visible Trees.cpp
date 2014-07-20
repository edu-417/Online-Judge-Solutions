#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int mu[N+1];
int n,m,C;
void cribaMu(){
    mu[1]=1;
    for(int i=1;i<=N;++i)
        for(int j=2*i;j<=N;j+=i)mu[j]-=mu[i];
    }
void doit(){
    scanf("%d%d",&n,&m);
    long long ans=0;
    for(int i=1;i<=min(m,n);++i)ans+=((long long)mu[i]*(m/i)*(n/i));
    printf("%lld\n",ans);
    }
int main(){
    cribaMu();
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
