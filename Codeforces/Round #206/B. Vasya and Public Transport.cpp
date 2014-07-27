#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
int c[4];
int a[N+5],b[N+5],sA[N+5],sB[N+5];
int n,m;
int main(){
    for(int i=0;i<4;++i)scanf("%d",c+i);
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<m;++i)scanf("%d",b+i);
    sort(a,a+n);sort(b,b+m);
    sA[0]=a[0];sB[0]=b[0];
    for(int i=1;i<n;++i)sA[i]=sA[i]+sA[i-1];
    for(int i=1;i<m;++i)sB[i]=sB[i]+sB[i-1];
    int ans=min(c[3],2*c[2]);
    for(int i=0;i<n;++i)ans=min(ans,c[2]+sA[i]*c[0]+(n-1-i));
    for(int i=0;i<m;++i)ans=min(ans,c[2]+sB[i]*c[0]+(m-1-i));
    ans=min(ans,(sA[n-1]+sB[m-1])*c[0]);
    printf("%d\n",ans);
    }
