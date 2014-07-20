#include<cstdio>
#include<cmath>
#include<algorithm>
#define EPS 1e-8
using namespace std;
int n;
#define Vector Point
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
    Point ort(){return Point(-y,x);}
    double mod(){return sqrt(x*x+y*y);}
    };
bool operator <(const Point &a, const Point &b){
    if(fabs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}
Point operator -(const Point &P1,const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
Point operator +(const Point &P1,const Point &P2){return Point(P1.x+P2.x,P1.y+P2.y);}
double cross(const Vector &A,const Vector &B){return A.x*B.y-A.y*B.x;}
double area(const Point &A,const Point &B,const Point &C){return cross(B-A,C-A);}
double dist(const Point &A,const Point &B,const Point &P){
    return fabs(area(A,B,P))*1.0/(B-A).mod();
    }
Point P[100005];
Point H[2*100005];
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    double x,y;
    for(int i=0;i<n;++i)scanf("%lf%lf",&x,&y),P[i]=Point(x,y);
    sort(P,P+n);
    int k=0;
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }

    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    n=k-1;
    
    double S=-1.0,p=-1.0,auxS,auxP;
    Point Q;
    for(int i=0,j=2,k=1,q;i<n;++i){
        while( area( H[i], H[ (i+1)%n ], H[ (j+1)%n ] ) > area( H[i], H[ (i+1)%n ], H[j]) )j=(j+1)%n;
        Q=H[j]-( H[ (i+1)%n ]-H[i] ).ort();
        while(k!=j && area(  H[j], Q, H[ (k+1)%n ] ) > area( H[j], Q, H[k] ) )k=(k+1)%n;
        if(i==0)q=j;
        while(q!=i && area( Q, H[j], H[ (q+1)%n ] ) > area( Q, H[j], H[q] ) )q=(q+1)%n;
        auxS=dist(H[i], H[ (i+1)%n ], H[j])*( dist(H[j], Q, H[k] ) + dist(H[j], Q, H[q] ) );
        auxP=dist(H[i], H[ (i+1)%n ], H[j])+( dist(H[j], Q, H[k] ) + dist(H[j], Q, H[q] ) );
        auxP*=2.0;
        if(S<0.0)S=auxS;
        S=min(S,auxS);
        if(p<0.0)p=auxP;
        p=min(p,auxP);
        }
    printf("%.2lf %.2lf\n",S,p);
    
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
