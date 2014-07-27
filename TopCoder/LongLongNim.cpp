#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[30];
bool dp[1<<30];
int main(){
    scanf("%d%d",&n,&m);
    printf("%d %d\n",n,m);
    int greater=0;
    for(int i=0;i<m;++i)scanf("%d",a+i),greater=max(greater,a[i]);
    printf("%d\n",greater);
    int l=greater*((1<<greater)+1);
    for(int i=0;i<=l;++i)
        if(!dp[i])for(int j=0;j<m && i+a[j]<=l;++j)dp[i+a[j]]=true;
    printf("llegue\n");
    int mod=0;
    for(int i=greater;i+greater<=l;++i){
        bool val=true;
        for(int j=0;j<greater;++j)if(dp[j]!=dp[i+j]){val=false;break;}
        if(val){mod=i;break;}
        }
    for(int i=0;i<n;++i)printf("%d: %d\n",i,dp[i]);
    
    printf("mod: %d\n",mod);
    if(mod==0){printf("error\n");return 0;}
    int ans=0;
    for(int i=1;i<=mod;++i)ans+=dp[i];
    ans*=(n/mod);
    for(int i=1;i<=(n%mod);++i)ans+=dp[i];
    printf("%d\n",n-ans);
    }
