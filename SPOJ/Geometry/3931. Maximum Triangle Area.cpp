#include<cstdio>
#include<complex>
#include<algorithm>
using namespace std;

//struct Point
typedef complex<int> Point;
#define X real()
#define Y imag()
//
#define Vector Point
#define N 50000

int n,x,y;
Point P[N+5];
Point H[N+5];
int cross(const Vector &A,const Vector &B){return A.X*B.Y-A.Y*B.X;}

bool cmp(const Point &A, const Point &B){
    if(A.X==B.X)return A.Y<B.Y;
    return A.X<B.X;
    }
int mod(int x,int n){return x==n? 0:x;}

bool doit(){
    scanf("%d",&n);
    if(n==-1)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    int ans=0;
    sort(P,P+n,cmp);
    int k=0;
    for(int i=0;i<n;++i){
        while(k>=2 && cross(H[k-1]-H[k-2],P[i]-H[k-2]) <= 0) --k;
        H[k++] = P[i];
    }

    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && cross(H[k-1]-H[k-2],P[i]-H[k-2]) <= 0) --k;
        H[k++] = P[i];
    }
    
    n=k-1;
    
    for(int i=0;i<n;++i)P[i]=H[i];
    
    for(int i=0,j=1,k=2;i<n;++i){
        if(i==j)j=mod(j+1,n);
        if(j==k)k=mod(k+1,n);
        while( cross( P[j]-P[i] , P[ mod(k+1,n) ]-P[i] ) >= cross( P[j]-P[i] , P[k]-P[i] ) )k=mod(k+1,n);
        if( cross( P[ mod(j+1,n) ]- P[i] , P[k]-P[i] ) >= cross( P[j]- P[i] , P[k]-P[i] ) )j=mod(j+1,n);
        ans=max(ans, cross( P[j]-P[i] , P[k]-P[i] ) );
        }
    printf("%.2lf\n",0.5*ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
