#include<cstdio>

using namespace std;

int n ,p, q;

int main(){
	scanf("%d%d%d", &n, &p, &q );

	double ans = 1.0 * p * n / ( p + q );
	printf("%.4lf\n", ans );
}
