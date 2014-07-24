#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
bool operator ==(const Point &a, const Point &b){
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b){
    return !(a==b);
}
bool operator <(const Point &a, const Point &b){
    if(fabs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}



vector <Point>  TangentLineThroughPoint(Point P, Point C, double r){
	vector <Point> X;
	
	double h2 = (C - P).mod2();
	if(h2 < r*r) return X;
	else
	{
		double d = sqrt(h2 - r*r);
		
		double m1 = (r*(P.x - C.x) + d*(P.y - C.y)) / h2;
		double n1 = (P.y - C.y - d*m1) / r;
		
		double n2 = (d*(P.x - C.x) + r*(P.y - C.y)) / h2;
		double m2 = (P.x - C.x - d*n2) / r;
		
		X.push_back(C + Point(m1, n1)*r);
		if(d != 0) X.push_back(C + Point(m2, n2)*r);
		
		return X;
	}
}

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D){
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}


int n,x,y,cx,cy,r;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    scanf("%d%d",&x,&y);
    Point P(x,y);
    vector<pair<double,double> > ans;
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&cx,&cy,&r);
        Point C(cx,cy);
        vector<Point> aux=TangentLineThroughPoint(P,C,r);
        Point Istart=lineIntersection(Point(0,0),Point(1,0),P,aux[0]);
        Point Iend=lineIntersection(Point(0,0),Point(1,0),P,aux[1]);
        if(Istart.x>Iend.x)swap(Istart,Iend);
        ans.push_back(make_pair(Istart.x,Iend.x));
        }
    sort(ans.begin(),ans.end());
    double start=ans[0].first,end=ans[0].second;
    for(int i=1;i<ans.size();++i){
        if( fabs(ans[i].first-end)<EPS || ans[i].first<end )end=max(end,ans[i].second);
        else{
            printf("%.2f %.2f\n",start,end);
            start=ans[i].first,end=ans[i].second;
            }
        }
    printf("%.2f %.2f\n",start,end);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
