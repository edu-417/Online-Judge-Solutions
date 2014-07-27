#include<cstdio>
#include<algorithm>
using namespace std;
int x,y,a,b;
bool doit(){
    if(scanf("%d%d%d%d",&x,&y,&a,&b)!=4)return false;
    int d=__gcd(x,y);
    int aux=(x/d)*y;
    int ans=b/aux-(a-1)/aux;
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
