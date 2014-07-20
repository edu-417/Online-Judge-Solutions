#include<cstdio>
#include<cmath>
#include<complex>
using namespace std;
//struct Point
typedef complex<double> Point;
#define Vector Point
#define X real()
#define Y imag()
//

Point operator / (const Point &A,double k){return Point(A.X/k,A.Y/k);}
Vector ortogonal(const Vector &A){return Vector(-A.Y,A.X);}
double modulo2(const Vector &A){return A.X*A.X+A.Y*A.Y;}
double modulo(const Vector &A){return sqrt(A.X*A.X+A.Y*A.Y);}
Vector unit(const Vector &A){return A/modulo(A);}
double cross(const Vector &A,const Vector &B){return A.X*B.Y-A.Y*B.X;}

Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D){
    Vector AB=B-A;
    Vector AC=C-A;
    Vector CD=D-C;
    return A+(cross(AC,CD)/cross(AB,CD))*AB;
    }
    
Point circumCenter(const Point &A,const Point &B, const Point &C){
    Point mAB=(A+B)*0.5;
    Point mBC=(B+C)*0.5;
    Vector AB=B-A;
    Vector BC=C-B;
    return lineIntersection(mAB,mAB+ortogonal(AB),mBC,mBC+ortogonal(BC));
    }
    
Point inCenter(const Point &A,const Point &B, const Point &C){
    Vector AB=B-A,AC=C-A,BA=B-A,BC=C-B;
    Vector bisA=unit(AB)+unit(AC);
    Vector bisB=unit(BA)+unit(BC);
    return lineIntersection(A,A+bisA,B,B+bisB);
    }


char c[100],s[1000000];
bool doit(){
    if(!gets(s))return false;
    int ct=0,Ct=0;
    sscanf(s,"%s%n",c,&Ct);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
