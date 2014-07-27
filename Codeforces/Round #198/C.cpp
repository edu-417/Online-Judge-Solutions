#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int n;
int a[N+5];
long long s[N+5];

long long left(int idx){
    if(idx==0)return 0;
    long long ans=(long long)idx*a[idx]-s[idx-1];
    if(ans<0)ans=-ans;
    return ans;
    }
    
long long right(int idx){
    if(idx==n-1)return 0;
    long long ans=(s[n-1]-s[idx])-(long long)(n-1-idx)*a[idx];
    if(ans<0)ans=-ans;
    return ans;
    }
    
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    s[0]=a[0];
    for(int i=1;i<n;++i)s[i]=s[i-1]+a[i];
    long long ans=0;
    for(int i=0;i<n;++i)ans+=left(i)+right(i);
    for(int i=0;i<n;++i)ans+=a[i];
    long long d=__gcd(ans,(long long)n);
    ans/=d;
    n/=d;
    printf("%I64d %d\n",ans,n);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
