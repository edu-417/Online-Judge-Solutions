#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300000
int n;
int p[N+5];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",p+i);
    sort(p,p+n);
    long long ans=0;
    for(int i=0;i<n;++i)ans+=(long long)abs(i+1-p[i]);
    printf("%I64d\n",ans);
    }
