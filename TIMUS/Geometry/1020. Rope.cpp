#include<cstdio>
#include<cmath>
using namespace std;

double pi=2.0*acos(0.0);

int n;
double r,x,y;
struct punto{
	double x,y;
	punto(){}
	punto(double _x, double _y){
		x=_x;
		y=_y;
		}
	};

punto operator -(punto p1,punto p2){
	return punto(p1.x-p2.x,p1.y-p2.y);
	}
double mod(punto p1){
	return sqrt(p1.x*p1.x+p1.y*p1.y);
	}
punto p[105];

int main(){
	scanf("%d%lf",&n,&r);
	for(int i=0;i<n;++i)scanf("%lf%lf",&x,&y),p[i]=punto(x,y);
	double ans=2*pi;
	for(int i=0;i<n;++i)ans+=mod(p[i]-p[(i+1)%n]);
	printf("%.2lf\n",ans);
	}
