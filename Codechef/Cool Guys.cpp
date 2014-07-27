#include<cstdio>
#include<algorithm>
using namespace std;
int n,C;
void doit(){
    scanf("%d",&n);
    long long ans=0;
    int sq=0;
    for(int i=1;i*i<=n;++i,++sq)ans+=n/i;
    for(int i=1;i*i<n;++i)if(n/i>sq)ans+=(n/i-sq);
    long long m=(long long)n*n;
    long long d=__gcd(m,ans);
    ans/=d,m/=d;
    printf("%lld/%lld\n",ans,m);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
