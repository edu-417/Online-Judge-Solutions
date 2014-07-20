#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define Vector Point
#define EPS 1e-8
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
    };

Point operator -(const Point &P1,const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
double cross(const Vector &A,const Vector &B){return A.x*B.y-A.y*B.x;}
double area(const Point &A,const Point &B,const Point &C){return cross(B-A,C-A);}
Point P[5];
Point start,end;
int left,right,top,bottom;
int C;
bool between(const Point &A, const Point &B, const Point &P){
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P){
    return fabs(area(A, B, P)) < EPS && between(A, B, P);
}
bool inside(const Point &P){
    return (int)P.x>=left && (int)P.x<=right && (int)P.y>=bottom && (int)P.y<=top;
    }

bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);

    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0)))
            return true;

    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}

void doit(){
    double x,y;
    scanf("%lf%lf",&x,&y);start=Point(x,y);
    scanf("%lf%lf",&x,&y);end=Point(x,y);
    scanf("%d%d",&left,&top);
    scanf("%d%d",&right,&bottom);
    if(left>right)swap(left,right);
    if(bottom>top)swap(bottom,top);
    P[0]=Point(right,bottom);
    P[1]=Point(right,top);
    P[2]=Point(left,top);
    P[3]=Point(left,bottom);
    P[4]=Point(right,bottom);
    bool inStart=inside(start);
    bool inEnd=inside(end);
    bool intersection=false;
    for(int i=0;i<4;++i)
        if(intersects(P[i],P[i+1],start,end))intersection=true;
    bool ans=inStart||inEnd||intersection;
    printf("%s\n",ans?"T":"F");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
