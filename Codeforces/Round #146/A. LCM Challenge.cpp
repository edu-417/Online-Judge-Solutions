#include<cstdio>
#include<algorithm>
using namespace std;
int n;

long long lcm(long long x,long long y){
    return x/__gcd(x,y)*y;
    }
long long f(int n){
    if(n<3)return n;
    if(n&1)return lcm(lcm(n,n-1),n-2);
    return max(f(n-1),lcm(lcm(n,n-1),n-3));
    }
int main(){
    scanf("%d",&n);
    printf("%I64d\n",f(n));
    }
