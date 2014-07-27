#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int n,x,m;
int a[N+5];
long long f(){
    sort(a,a+m);
    reverse(a,a+m); 
    long long ans=0;
    int d=min(m,x-1);
    for(int i=0;i<d;++i)
        if(d<m && d>=0)ans+=a[i]-a[d];
        else ans+=a[i];
    if(d<m && d>=0)ans+=((long long)a[d]*x);
    return ans;
    }
int main(){
    scanf("%d",&n);
    m=0;
    for(int i=0;i<n;++i){
        scanf("%d",a+m);
        if(a[m]<0)a[m]=-a[m],++m;
        }
    scanf("%d",&x);
    long long ans=f();
    printf("%lld\n",ans);
    }
