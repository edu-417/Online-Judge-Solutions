#include<cstdio>
#include<algorithm>
using namespace std;
int p,q,ex,ey,sx,sy;
int main(){
    scanf("%d%d",&p,&q);scanf("%d%d",&sx,&sy);scanf("%d%d",&ex,&ey);
    if(p<0)p=-p;
    if(q<0)q=-q;
    int d=__gcd(p,q);
    long long x=ex-sx,y=ey-sy;
    bool ans=false;
    if(x%d==0 && y%d==0)ans=true;
    printf("%s\n",ans?"YES":"NO");
    return false;
    }
