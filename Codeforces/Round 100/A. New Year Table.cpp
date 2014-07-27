#include<cstdio>
#include<cmath>
int n,R,r;
int main(){
    scanf("%d%d%d",&n,&R,&r);
    bool ans;
    if(2.0*acos(0.0)>=n*asin(r*1.0/R-r))ans=true;
    else ans=false;
    printf("%s\n",ans?"YES":"NO");
    }
