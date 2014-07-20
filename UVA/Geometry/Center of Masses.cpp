#include<cstdio>
#include<cmath>
#include<algorithm>
#define EPS 1e-8
using namespace std;
#define Vector Point
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
    };
Point operator -(const Point &P1,const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
bool operator <(const Point &a, const Point &b){
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
    }
double cross(const Vector &P1,const Vector &P2){return P1.x*P2.y-P1.y*P2.x;}
double area(const Point &P1,const Point &P2,const Point &P3){return cross(P2-P1,P3-P1);}
Point P[105],H[105];
int n;
double area(){
    double S=0.0;
    for(int i=0;i<n;++i)S+= ( H[i].x*H[i+1].y - H[i].y*H[i+1].x );
    return S;
    }

bool doit(){
    scanf("%d",&n);
    if(n<3)return false;
    int x,y;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
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
    H[n]=H[0];
    double cx=0.0;
    for(int i=0;i<n;++i)cx+=( H[i].x + H[i+1].x )*( H[i].x*H[i+1].y - H[i].y*H[i+1].x );
    double cy=0.0;
    for(int i=0;i<n;++i)cy+=( H[i].y + H[i+1].y )*( H[i].x*H[i+1].y - H[i].y*H[i+1].x );
    double S=area();
    S*=3.0;
    cx/=S;
    cy/=S;
    printf("%.3lf %.3lf\n",cx,cy);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
