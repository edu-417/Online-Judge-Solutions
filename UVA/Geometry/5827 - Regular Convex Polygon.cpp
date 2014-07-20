#include<cstdio>
#include<cstring>
#include<cmath>
#define PI 2.0*acos(0.0)
#define EPS 1e-5
#define Vector Point
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
    Point ort(){return Point(-y,x);}
    };

Point operator -(const Point &P1, const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
Point operator +(const Point &P1, const Point &P2){return Point(P1.x+P2.x,P1.y+P2.y);}
Point operator *(const Point &P1, const double &k){return Point(P1.x*k,P1.y*k);}
Point operator /(const Point &P1, const double &k){return Point(P1.x/k,P1.y/k);}

double cross(const Vector &P1,const Vector &P2){return P1.x*P2.y-P1.y*P2.x;}
double dot(const Vector &P1,const Vector &P2){return P1.x*P2.x+P1.y*P2.y;}

double dist(const Point &P1,const Point &P2){return hypot(P1.x-P2.x,P1.y-P2.y);}
Point circumcenter(const Point &A, const Point &B,const Point &C){
    return (A+B+(A-B).ort()*dot(C-B,A-C)/cross(A-B,A-C))/2.0;
    }


char c[1000];
double R;
Point P[3];
int bs(const int &n,const double &x){
    int lo=1,hi=n/2;
    while(lo<hi){
        int m=lo+(hi-lo)/2;
        double d=2.0*R*sin(PI*m/n);
        if(d>x+EPS || fabs(d-x)<EPS)hi=m;
        else lo=m+1;
        }
    return lo;
    }
bool doit(){
    double x,y;
    for(int i=0;i<3;++i){
        gets(c);
        if(i==0 && strcmp(c,"END")==0)return false;
        sscanf(c,"%lf%lf",&x,&y),P[i]=Point(x,y);
        }
    Point O=circumcenter(P[0],P[1],P[2]);
    R=dist(P[0],O);
    int ans;
    for(int i=3;i<=1000;++i){
        double a=dist(P[0],P[1]);
        int n1=bs(i,a);
        double d=2.0*R*sin(PI*n1/i);
        if(!(fabs(d-a)<EPS))continue;
        double b=dist(P[1],P[2]);
        int n2=bs(i,b);
        d=2.0*R*sin(PI*n2/i);
        if(!(fabs(d-b)<EPS))continue;
        ans=i;
        break;
        }
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
