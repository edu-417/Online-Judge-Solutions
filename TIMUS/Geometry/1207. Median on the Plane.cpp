#include<cstdio>
#include<complex>
#include<algorithm>
using namespace std;
//struct Point
typedef complex<int> Point;
#define x real()
#define y imag()
//
#define Vector Point
#define N 100000
int _x,_y,n;
Point P[N+5];
int ind[N+5];

long long cross(const Vector &A,const Vector &B){
    return (long long)A.x*B.y-(long long)A.y*B.x;
    }
    
bool cmp(const int &a,const int &b){
    if(P[a].x==P[b].x)return P[a].y<P[b].y;
    return P[a].x<P[b].x;
    }

bool cmp2(const int &a,const int &b){
    return cross( P[a]-P[ind[0]],P[b]-P[ind[0]] )>0;
    }
    
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",&_x,&_y),P[i]=Point(_x,_y);
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,cmp);
    sort(ind+1,ind+n,cmp2);
    printf("%d %d\n",1+ind[0],1+ind[n/2]);
    }
