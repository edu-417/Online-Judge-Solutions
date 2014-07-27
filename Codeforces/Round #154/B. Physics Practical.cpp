#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
#define N 100000
int a[N+5];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    int ans=n;
    for(int i=0;i<n;++i){
        int pos=upper_bound(a,a+n,2*a[i])-a;
        ans=min(ans,i+max(0,(n-pos)));
        }
    printf("%d\n",ans);
    }
