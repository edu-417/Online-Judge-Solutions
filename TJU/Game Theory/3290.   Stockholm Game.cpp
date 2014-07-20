#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000
int a[N+5];
int h,n,C;
void doit(){
    scanf("%d",&n);
    a[0]=0;
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=n;i>0;i-=2)ans^=(a[i]-a[i-1]-1);
    printf("%s\n",ans==0?"wqb will win":"windy will win");
    }

int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
