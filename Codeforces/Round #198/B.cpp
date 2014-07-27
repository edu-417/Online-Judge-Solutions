#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define EPS 1e-9
#define Vector Point

int n;
struct Point{
    int x, y;
    Point(){}
    Point(int a, int b) { x = a; y = b; }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }

bool operator <(const Point &a, const Point &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool operator ==(const Point &a, const Point &b)
{
    return a.x==b.x && a.y==b.y;
}

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

double area(const vector <Point> &P){
    int n = P.size();
    double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return fabs(A/2);
}

vector <Point> ConvexHull(vector<Point> &P){
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

bool doit(){
    if(scanf("%d",&n)!=1)return false;
    int x,y;
    vector<Point> P;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P.push_back(Point(x,y));
    vector<Point> hull=ConvexHull(P);
    double ans=0.0;
    if(hull.size()==4){
        ans=area(hull);
        }
    else{
        for(int i=0;i<n;++i){
            bool valid=true;
            double S=area(hull);
            printf("%lf\n",S);
            for(int j=0;j<3;++j){
                if(P[i]==hull[j])valid=false;
                }
            if(!valid)continue;
            for(int j=0;j<3;++j){
                double aux=fabs( area( hull[j],hull[(j+1)%3],P[i] ) );
                if(aux>0)ans=max(ans,S-aux );
                }
            }
        
        }
    printf("%.10lf\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
