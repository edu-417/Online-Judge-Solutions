#include<cstdio>
#include<complex>
using namespace std;

//struct Point
typedef complex<double> Point;
#define X real()
#define Y imag()
//
#define Vector Point

double modulo(const Vector &A){return sqrt(A.X*A.X+A.Y*A.Y);}
Vector ortogonal(const Vector &A){return Vector(-A.Y,A.X);}
double cross(const Vector &A,const Vector &B){return A.X*B.Y-A.Y*B.X;}

Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D){
    Vector AB=B-A;
    Vector AC=C-A;
    Vector CD=D-C;
    return A+(cross(AC,CD)/cross(AB,CD))*AB;
    }
    
Point circumCenter(const Point &A,const Point &B,const Point &C){
    Point mAB=(A+B)*0.5;
    Point mBC=(B+C)*0.5;
    Vector AB=B-A;
    Vector BC=C-B;
    return lineIntersection(mAB,mAB+ortogonal(AB),mBC,mBC+ortogonal(BC));
    }
    
int x,y;
Point P[3];

bool doit(){
    for(int i=0;i<3;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    if(P[0].X==-1)return false;
    Point A=(P[0]+P[1])*0.5;
    Point B=(P[1]+P[2])*0.5;
    Point C=(P[0]+P[2])*0.5;
    Point O=circumCenter(A,B,C);
    double R=modulo(A-O);
    printf("%.6lf %.6lf %.6lf\n",O.X,O.Y,R);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
