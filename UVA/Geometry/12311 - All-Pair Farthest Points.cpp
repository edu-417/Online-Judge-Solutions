#include<cstdio>
#include<complex>
using namespace std;

//struct Point
typedef complex<int> Point;
#define Vector Point
#define X real()
#define Y imag()
//

#define N 30000

Point P[N+5];
int n,x,y;
int far[N+5];

long long cross(const Vector &A, const Vector &B){return (long long)A.X*B.Y-(long long)A.Y*B.X;}

long long mod2(const Vector & A){return (long long)A.X*A.X+(long long)A.Y*A.Y;}

int mod(int x,int n){
    return x==n? 0:x;
    }

void updateFar(int idx,int idx2){
    if(mod2( P[idx]-P[far[idx]] ) == mod2( P[idx]-P[idx2] ) )far[idx]=min(far[idx],idx2);
    if(mod2( P[idx]-P[far[idx]] ) < mod2( P[idx]-P[idx2] ) )far[idx]=idx2;
    }
    
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    for(int i=0;i<n;++i)far[i]=i;
    for(int i=0,j=1;i<n;++i){
        while( cross( P[ mod(i+1,n) ]-P[i] , P[j]-P[i] ) < cross( P[ mod(i+1,n) ]-P[i] , P[ mod(j+1,n) ]-P[i] ) )j=mod(j+1,n);
        updateFar(i,j);
        updateFar(j,i);
        updateFar(mod(i+1,n),j);
        updateFar(j,mod(i+1,n));
        }
    
    for(int i=0;i<n;++i)printf("%d\n",far[i]+1);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
