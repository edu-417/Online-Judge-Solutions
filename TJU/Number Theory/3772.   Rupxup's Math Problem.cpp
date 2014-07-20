#include<cstdio>
#include<cmath>
#define max(a,b) a>b? a:b
int n,C;
void doit(){
    scanf("%d",&n);
    double sq=sqrt(n);
    int s=int(sq);
    long long ans=0;
    for(int i=1;i<=s;++i)ans+=n/i;
    for(int i=1;i<sq;++i)ans+=max(0,n/i-s);
    printf("%lld\n",ans);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
