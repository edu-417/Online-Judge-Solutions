#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    int x=n,y=m;
    if(x>y)swap(x,y);
    int ans=0;
    if(x==0)ans=0;
    else if(x==1)ans=y;
    else if(x==2 && y==2)ans=4;
    else if(x==2)ans=2 * ( 2*(y/4) + min(2,y%4) );
    else ans=x*y/2 + ( (x*y)&1 );
    printf("%d knights may be placed on a %d row %d column board.\n",ans,n,m);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
