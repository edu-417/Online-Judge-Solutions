#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define oo (1LL)<<60
using namespace std;

long long s1[505],s2[505];
long long dp[505];
int n,m;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%lld",s1+i);
    scanf("%d",&m);
    for(int i=0;i<m;++i)scanf("%lld",s2+i);
    for(int i=1;i<=n;++i)dp[i]=oo;
    dp[0]=-oo;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            if(s1[i]==s2[j]){
                int d=upper_bound(dp,dp+n+1,s1[i])-dp;
                printf("%d %d %d %lld\n",i,j,d,dp[d]);
                if(dp[d-1]<s1[i] && s1[i]<dp[d])dp[d]=s1[i];
                }
            }
    int ans=0;
    for(int i=0;i<=n;++i)if(dp[i]==oo)ans=i;
    printf("%d\n",ans);
    printf("\n");
    for(int i=0;i<ans;++i)printf("%s%d",i==0?"":" ",dp[i]);
    printf("\n");
    }
