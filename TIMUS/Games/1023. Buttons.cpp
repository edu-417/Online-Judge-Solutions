#include<cstdio>
#include<algorithm>
using namespace std;
#define oo 1<<30
int n;
int main(){
    scanf("%d",&n);
    int ans=oo;
    for(int i=1;i*i<=n;++i)
        if(n%i==0){
            if(i>2)ans=min(ans,i-1);
            if(n/i>2)ans=min(ans,n/i-1);
            }
    if(ans==oo)printf("0\n");
    else printf("%d\n",ans);
    }
