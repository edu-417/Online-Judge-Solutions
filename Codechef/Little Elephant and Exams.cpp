#include<cstdio>
#include<algorithm>
using namespace std;
#define N 50
int a[N+5],b[N+5],p[N+5];
int n,C;
double dp[N+5][(1<<16)+5];
double f(int pos,int mask){
    if(pos==n)return 1.0;
    double &ret=dp[pos][mask];
    if(ret>-0.5)return ret;
    double ans=0.0;
    if( (mask>>a[pos])&1 )ans+=p[pos]*f(pos+1,mask^(1<<a[pos]))/100.0;
    if( (mask>>b[pos])&1 )ans+=(100-p[pos])*f(pos+1,mask^(1<<b[pos]))/100.0;
    return ret=ans;
    }
    
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d%d",p+i,a+i,b+i),--a[i],--b[i];
    int mask=(1<<16)-1;
    for(int i=0;i<n;++i)
        for(int j=0;j<(1<<16);++j)dp[i][j]=-1.0;
    double ans=f(0,mask);
    printf("%.6lf\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();    
    }
