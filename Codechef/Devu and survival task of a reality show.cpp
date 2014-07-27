#include<cstdio>
#include<algorithm>
using namespace std;

#define N 100000

int a[N + 5];
int count[N + 5];

int n;

pair<int, int > pos1[20];
pair<int, int > pos2[20];

struct participant{
	int id;
	int votes;
};

bool operator < ( participant p1, participant p2 ){
	if( p1.votes == p2.votes )return p1.id > p2.id;
	return p1.votes < p2.votes;
}

participant P[N + 5];

bool isValid( int p, int idx ){
	return true;
}

void doCase(){
	scanf("%d", &n);

	for( int i = 0 ; i < n; ++i )count[i] = 0;
	
	for( i = 0; i < n - 2; ++i ){
		scanf("%d", a + i);
		count[ a[i] ]++;
	}

	for( i = 0; i < n; ++i ){
		P[i].id = i;
		P[i].votes = count[i];
	}

	sort( P, P + n );

	pos1[0] = make_pair( P[n - 1].id, P[0].id );
	pos1[1] = make_pair( P[n - 1].id, P[n - 2].id );
	pos1[2] = make_pair( P[0].id, P[1].id );
	pos1[3] = make_pair( P[1].id, P[n - 2].id );
	pos1[4] = make_pair( P[n - 1].id, n - 2 );
	pos1[5] = make_pair( P[0].id, n - 2 );
	pos1[6] = make_pair( P[n - 2].id, n - 2 );
	pos1[7] = make_pair( P[1].id, n - 2 );

	pos2[0] = make_pair( P[n - 1].id, P[0].id );
	pos2[1] = make_pair( P[n - 1].id, P[n - 2].id );
	pos2[2] = make_pair( P[0].id, P[1].id );
	pos2[3] = make_pair( P[1].id, P[n - 2].id );
	pos2[4] = make_pair( P[n - 1].id, n - 1 );
	pos2[5] = make_pair( P[0].id, n - 1 );
	pos2[6] = make_pair( P[n - 2].id, n - 1 );
	pos2[7] = make_pair( P[1].id, n - 1 );

	int ans = 0;
	pair<int, int> > vote[2];
	
	for( int i = 0; i < 8; ++i )
		for(in j = 0; j < 8; ++j){
			if( valid(1, i) && isValid(2, i) ){
				count[pos1[i].first]++;
				count[pos1[i].second]++;
				count[pos2[i].first]++;
				count[pos2[i].second]++;

				for( k = 0; k < n; ++k ){
					P[k].id = k;
					P[k].votes = count[k];
				}

				sort( P, P + n );

				int cnt = 0;
				if( count[n - 1] ) > count[ P[0].id ] && count[n - 1] < count[ P[n - 1].id ] )++cnt;

				if( count[n - 2] ) > count[ P[0].id ] && count[n - 2] < count[ P[n - 1].id ] )++cnt;

				if( cnt >= ans ){
					ans = cnt;
					vote[0].first = make_pair( pos1[i].first);
					vote[0].second = make_pair( pos1[i].second);
					vote[1].first = make_pair( pos1[i].first);
					vote[1].second = make_pair( pos1[i].second);
				}

			}
		}

	if( ans == 0 ){
		printf("none\n");
		printf("%d %d\n", vote[0].first, vote[0].second );
		printf("%d %d\n", vote[1].first, vote[1].second );
	}
	else {
		printf("%s\n", ans == 1? "one": "both");
		printf("%d %d\n", vote[0].first, vote[0].second );
		printf("%d %d\n", vote[1].first, vote[1].second );
	}
}

int main(){
	scanf("%d", &C);

	for( int i = 0; i < C; ++i)doCase();
}
