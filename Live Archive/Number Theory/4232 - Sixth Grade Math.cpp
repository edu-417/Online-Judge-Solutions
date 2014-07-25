#include<cstdio>
#include<algorithm>
using namespace std;
int caso,a,b,C;
void doit(){
    scanf("%d%d",&a,&b);
    int gcd=__gcd(a,b);
    int lcm=a/gcd*b;
    printf("%d %d %d\n",++caso,lcm,gcd);
    }
    
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
