#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 200000

char s[ N + 5 ];

int map[256], parent[256] ;

int n, m, pa, pb;
char a[2], b[2];


int main(){
	scanf( "%d%d", &n, &m );

	scanf("%s", s );

	for( int i = 0; i < 256; ++i)map[i] = i;
	for( int i = 0; i < 256; ++i)parent[i] = i;
	
	for(int i = 0; i < m; ++i ){
		scanf("%1s%1s", a, b);
		pa = parent[a[0]];
		pb = parent[b[0]];
		
		map[ pa ] = b[0];
		map[ pb ] = a[0];

		parent[a[0]] = pb;
		parent[b[0]] = pa;
	}

	for( int i = 0; i < n; ++i )putchar( map[s[i]] );
	printf("\n");
	
}
