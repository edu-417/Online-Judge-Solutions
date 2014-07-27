#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 4000
#define oo 1e200
#define eps 1e-3
double a[N+5];
int n;

bool isInt(double d){
    return fabs(ceil(d)-floor(d))<eps;
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    double sum=0.0;
    for(int i=0;i<2*n;++i)scanf("%lf",a+i),sum+=a[i];
    int cnt=0;
    int sumInt=0;
    for(int i=0;i<2*n;++i)if(isInt(a[i]))++cnt;
    for(int i=0;i<2*n;++i)sumInt+=int(a[i]);
    double ans=oo;
    for(int i=sumInt+max(0,n-cnt);i<=sumInt+min(2*n-cnt,n);++i)ans=min(ans,fabs(sum-i));
    printf("%.3lf\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
