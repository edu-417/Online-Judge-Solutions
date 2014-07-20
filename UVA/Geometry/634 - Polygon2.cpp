#include<cstdio>
#include<algorithm>
using namespace std;
#define Vector Point
#define N 1000
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y){
        x=_x,y=_y;
        }
    };

Point operator -(const Point P1,const Point P2){
    return Point(P1.x-P2.x,P1.y-P2.y);
    }

int cross(const Vector &A, const Vector &B){
    return A.x*B.y-A.y*B.x;
    }

int area(const Point &A,const Point &B,const Point &C){
    return cross(B-A,C-A);
    }
    
int n,x,y;

Point P[N+5];
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    scanf("%d%d",&x,&y);
    Point A(x,y);
    int cnt=0;
    for(int i=0; i<n; i++){
        int inf = i, sup = (i+1)%n;
        if(P[inf].y > P[sup].y) swap(inf, sup);
        if(P[inf].y <= A.y && A.y < P[sup].y)
            if(area(A, P[inf], P[sup]) > 0)
                cnt++;
    }
    printf("%s\n",(cnt%2)==1?"T":"F");
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
