#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int n;
int a[N+5];

bool f(int m,long long x){
    long long aux=0;
    for(int i=1;i<n;++i){
        if(a[i]-m>a[0])return false;
        aux+=max(0,a[i]-m);
        }
    if(aux<=x)return true;
    return false;
    }
    
int bs(long long x){
    int lo=0,hi=a[n-1];
    while(lo<hi){
        int m=lo+(hi-lo)/2;
        if(f(m,x))hi=m;
        else lo=m+1;
        }
    return lo;
    }
    
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    long long x=(long long)a[0]*(n-2);
    int ans=bs(x);
    printf("%d\n",ans+a[0]);
    }
