#include<cstdio>
#include<cmath>
#define EPS 1e-8
#define Vector Point
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
    Point ort(){return Point(-y,x);}
    };

Point operator -(const Point &P1, const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
Point operator +(const Point &P1, const Point &P2){return Point(P1.x+P2.x,P1.y+P2.y);}
Point operator *(const Point &P1, double k){return Point(P1.x*k,P1.y*k);}
Point operator /(const Point &P1, double k){return Point(P1.x/k,P1.y/k);}
double dot(const Point &P1,const Point &P2){return P1.x*P2.x+P1.y*P2.y;}
double cross(const Vector &P1,const Vector &P2){return P1.x*P2.y-P1.y*P2.x;}

double dist(const Point &P1,const Point &P2){return hypot(P1.x-P2.x,P1.y-P2.y);}

Point circumcenter(const Point &A, const Point &B, const Point &C){
    return (A + B + (A - B).ort() * dot(C - B, A - C) / cross(A - B, A - C)) / 2;
}
Point P[3];
bool doit(){
    int x,y;
    for(int i=0;i<3;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    bool val=false;
    for(int i=0;i<3;++i)if(P[i].x!=-1 || P[i].y!=-1){val=true;break;}
    if(!val)return false;
    Point A=(P[0]+P[1])/2;
    Point B=(P[1]+P[2])/2;
    Point C=(P[2]+P[0])/2;
    Point O=circumcenter(A,B,C);
    double R=dist(O,A);
    printf("%.6lf %.6lf %.6lf\n",O.x,O.y,R);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
