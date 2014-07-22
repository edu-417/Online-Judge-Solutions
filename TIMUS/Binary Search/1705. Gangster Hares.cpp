#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 1000
long long n,sq;
int C;
bool p(long long x){
    return x-sq==(n/sq)-(n/x);
}
long long bs(){
	long long lo=sq, hi=n+1;
	while(lo<hi){
		long long mid=lo+(hi-lo+1)/2;
		if(!p(mid))hi=mid-1;
		else lo=mid;
	}
	return lo;
}
void doit(){
    scanf("%I64d",&n);
    sq=(long long)ceil(sqrt(n*1.0));
    long long ans=bs();
    printf("%I64d\n",ans);
}

int main(){
    scanf("%d",&C);
	for(int i=0;i<C;++i)doit();
}
