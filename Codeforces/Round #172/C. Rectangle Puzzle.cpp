#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define PI 2.0*acos(0.0)
#define Vector Point
#define EPS 1e-9
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x;y=_y;}
    };

Point operator +(const Point &A,const Point &B){return Point(A.x+B.x,A.y+B.y);}
Point operator -(const Point &A,const Point &B){return Point(A.x-B.x,A.y-B.y);}
Point operator *(const Point &A,const double &k){return Point(A.x*k,A.y*k);}
Point operator /(const Point &A,const double &k){return Point(A.x/k,A.y/k);}

bool operator ==(const Point &a, const Point &b){ 
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS; 
} 
bool operator !=(const Point &a, const Point &b){ 
    return !(a==b); 
} 
bool operator <(const Point &a, const Point &b){ 
    if(abs(a.x - b.x) > EPS) return a.x < b.x; 
    return a.y + EPS < b.y; 
} 
double cross(const Vector &A ,const Vector &B){return A.x*B.y-A.y*B.x;}
double area(const Point &A, const Point &B, const Point &C){ return cross(B-A,C-A);}
Vector rotation(const Vector &A, double alfa){return Vector(A.x*cos(alfa)+A.y*sin(alfa),A.y*cos(alfa)-A.x*sin(alfa));}

Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D){
    return A+(B-A)*cross(C-A,D-C)/cross(B-A,D-C);
    }

bool between(const Point &A, const Point &B,const Point &P){
    return P.x>=min(A.x,B.x) && P.x<=max(A.x,B.x) && P.y>=min(A.y,B.y) && P.y<=max(A.y,B.y);
    }
bool onSegment(const Point &A,const Point &B,const Point &P){
    return abs(area(A,B,P))<EPS && between(A,B,P);
    }

bool intersects(const Point &P1, const Point & P2, const Point &P3,const Point &P4){
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
    
double area(const vector <Point> &P){ 
    int n = P.size();
    double A = 0; 
    for(int i=1; i<=n-2; i++) 
        A += area(P[0], P[i], P[i+1]); 
    return abs(A/2); 
} 

vector <Point> ConvexHull(vector <Point> P) 
{ 
    sort(P.begin(),P.end()); 
    int n = P.size(),k = 0; 
    Point H[2*n]; 
      
    for(int i=0;i<n;++i){ 
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k; 
        H[k++] = P[i]; 
    } 
      
    for(int i=n-2,t=k;i>=0;--i){ 
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k; 
        H[k++] = P[i]; 
    } 
      
    return vector <Point> (H,H+k-1); 
} 
int w,h,angle;

vector<Point> P;
Point A[4],B[4];
int main(){
    scanf("%d%d%d",&w,&h,&angle);
    double alfa=PI*angle/180.0;
    A[0]=Point(w/2.0,h/2.0);
    A[1]=Point(-w/2.0,h/2.0);
    A[2]=Point(-w/2.0,-h/2.0);
    A[3]=Point(w/2.0,-h/2.0);
    for(int i=0;i<4;++i)B[i]=rotation(A[i],alfa);
    //for(int i=0;i<4;++i)printf("%lf %lf\n",A[i].x,A[i].y);
    //printf("rotate:\n");
    //for(int i=0;i<4;++i)printf("%lf %lf\n",B[i].x,B[i].y);
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j){
            if(intersects(A[i],A[(i+1)%4],B[j],B[(j+1)%4]))
            if( abs( cross(A[i]-A[(i+1)%4],B[j]-B[(j+1)%4] ) ) <EPS ){
                if( onSegment(A[i],A[(i+1)%4],B[j]))P.push_back(B[j]);
                if( onSegment(A[i],A[(i+1)%4],B[(j+1)%4]))P.push_back(B[(j+1)%4]);
                if( onSegment(B[j],B[(j+1)%4],A[i]))P.push_back(A[i]);
                if( onSegment(B[j],B[(j+1)%4],A[(i+1)%4]))P.push_back(A[(i+1)%4]);
                }
            else P.push_back(lineIntersection(A[i],A[(i+1)%4],B[j],B[(j+1)%4]));
            }
    //for(int i=0;i<P.size();++i)printf("%lf %lf\n",P[i].x,P[i].y);
    vector<Point> H=ConvexHull(P);
    //for(int i=0;i<H.size();++i)printf("%lf %lf\n",H[i].x,H[i].y);
    double ans=area(H);
    printf("%lf\n",ans);
    }
