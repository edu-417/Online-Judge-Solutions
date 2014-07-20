#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int a[N+5];
int h,n;
bool doit(){
    scanf("%d%d",&h,&n);
    if(h==0 && n==0)return false;
    a[0]=0;
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=n;i>0;i-=2)ans^=(a[i]-a[i-1]-1);
    printf("%s\n",ans==0?"Lose":"Win");
    return true;
    }

int main(){
    while(1)if(!doit())break;    
    }
