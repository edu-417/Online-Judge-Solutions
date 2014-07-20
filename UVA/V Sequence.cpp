#include<cstdio>
#include<algorithm>
#define N 200000
#define oo 1<<30
using namespace std;
int dp1[N+5],dp2[N+5],d[N+5],d1[N+5],d2[N+5],a[N+5];
int n;
int main(){
    scanf("%d",&n);
    int mayor=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),mayor=max(mayor,a[i]);
    for(int i=0;i<n;++i)a[i]=mayor-a[i];
    d[0]=-oo;
    for(int i=1;i<n;++i)d[i]=oo;
    int L=0;
    for(int i=0;i<n;++i){
        int j=upper_bound(d,d+n,a[i])-d;
        if(d[j-1]<a[i] && a[i]<d[j])L=max(L,j),d[j]=a[i];
        dp1[i]=L;
        d1[i]=d[L];
        }
    L=0;
    d[0]=-oo;
    for(int i=1;i<n;++i)d[i]=oo;
    for(int i=n-1;i>=0;--i){
        int j=upper_bound(d,d+n,a[i])-d;
        if(d[j-1]<a[i] && a[i]<d[j])L=max(L,j),d[j]=a[i];
        dp2[i]=L;
        d2[i]=d[L];
        }
    int ans=0;
    for(int i=0;i<n-1;++i){
        if(dp1[i]==1 && d1[i]>=d2[i+1])continue;
        if(dp2[i+1]==1 && d1[i]<=d2[i+1])continue;
        if(d1[i]==d2[i+1])ans=max(ans,dp1[i]+dp2[i+1]-1);
        else ans=max(ans,dp1[i]+dp2[i+1]);
        }
    printf("%d\n",ans);
    }
