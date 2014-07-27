#include<cstdio>
#include<algorithm>

using namespace std;
#define N 100000
#define oo 100000

int n;
int a[N + 5], p[N + 5];

int main(){
	scanf( "%d", &n );
	
	for( int i = 0; i < n; ++i )scanf( "%d%d", a + i, p + i );

	int ans = 0;
	int price = oo;
	
	for( int i = 0; i < n; ++i ){
		price = min( price, p[i] );
		ans = ans + price * a[i];
	}

	printf( "%d\n", ans );
}
