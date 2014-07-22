#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define Vector Point
struct Point{
    long long x,y;
    Point(){}
    Point(long long _x,long long _y){x=_x,y=_y;}
    long long mod2(){return x*x+y*y;}
    };

bool operator <(const Point &P1,const Point &P2){
    if(P1.x==P2.x)return P1.y<P2.y;
    return P1.x<P2.x;
    }
Point operator -(const Point &P1, const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
long long cross(const Vector &A, const Vector &B){return A.x*B.y-A.y*B.x;}
long long area(const Point &A, const Point &B, const Point &C){return cross(B-A,C-A);}
long long dist(const Point &P1,const Point P2){return (P2-P1).mod2();}
Point P[N],H[2*N];

int n,C;
void doit(){
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    sort(P,P+n);
    int k = 0;
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }

    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    n=k-1;
    long long ans=0;
    for(int i=0,j=2;i<n;++i){
        while(area(H[i],H[(i+1)%n],H[(j+1)%n])>area(H[i],H[(i+1)%n],H[j]))j=(j+1)%n;
        ans=max(ans, dist(H[i],H[j]));
        ans=max(ans, dist(H[(i+1)%n],H[j]));
        }
    printf("%lld\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
