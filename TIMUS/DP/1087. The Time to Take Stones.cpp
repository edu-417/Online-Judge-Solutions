#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000
#define M 50
int n,m;
int a[M+5];
bool dp[N+5];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d",a+i);
    sort(a,a+m);
    dp[a[0]]=false;
    for(int i=a[0];i<=n;++i)
        if(!dp[i])for(int j=0;j<m && i+a[j]<=n;++j)dp[i+a[j]]=true;
    for(int i=a[0];i<=n;++i)printf("%d: %d\n",i,dp[i]);
    printf("%d\n",dp[n]?1:2);
    }
