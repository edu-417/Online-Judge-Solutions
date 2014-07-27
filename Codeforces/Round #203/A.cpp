#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100
int n,m;
int a[N+5],b[N+5];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<m;++i)scanf("%d",b+i);
    sort(b,b+m);
    int ans=-1;
    for(int i=a[n-1];i<b[0];++i)if(2*a[0]<=i){
        ans=i;
        break;
        }
    printf("%d\n",ans);
    }
