#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int x,y,a,b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    if(a<=b)a=b+1;
    int ans=0;
    for(int i=a;i<=x;++i)
        for(int j=b;j<=min(i-1,y);++j)++ans;
    printf("%d\n",ans);
    for(int i=a;i<=x;++i)
        for(int j=b;j<=min(i-1,y);++j)printf("%d %d\n",i,j);
    }
