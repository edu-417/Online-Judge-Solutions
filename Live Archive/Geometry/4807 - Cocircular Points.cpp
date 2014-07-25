#include<cstdio>
#include<algorithm>
#include<complex>
using namespace std;

//struct Point
typedef complex<double> Point;
#define Vector Point
#define X real()
#define Y imag()
//

#define N 100
#define eps 1e-9
int n,x,y;
Point P[N+5];
double R[2][N+5];

Vector ortogonal(const Vector &A){return Vector(-A.Y,A.X);}
double cross(const Vector &A , const Vector &B){return A.X*B.Y-A.Y*B.X;}
double modulo2(const Vector &A){return A.X*A.X+A.Y*A.Y;}



Point lineIntersection(const Point &A, const Point &B,const Point &C, const Point &D){
    Vector AB=B-A;
    Vector AC=C-A;
    Vector CD=D-C;
    return A+( cross(AC,CD)/cross(AB,CD) )*AB;
    }

Point circleCenter(const Point & A,const Point &B,const Point &C){
    Point mAB=(A+B)*0.5;
    Point mBC=(B+C)*0.5;
    Vector AB=B-A;
    Vector BC=C-B;
    return lineIntersection(mAB,mAB+ortogonal(AB),mBC,mBC+ortogonal(BC));
    }

bool colineal(const Point &A,const Point &B,const Point &C){
    return fabs( cross(B-A,C-A) )<eps;
    }
    
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    
    int ans=2;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j){
            int cnt[2];
            cnt[0]=cnt[1]=0;
            for(int k=j+1;k<n;++k){
                if(k==i || k==j || colineal(P[i],P[j],P[k]))continue;
                Point C=circleCenter(P[i],P[j],P[k]);
                double aux=cross(P[j]-P[i],C-P[i]);
                if(aux>0 || fabs(aux)<eps)R[0][cnt[0]++]=modulo2(P[i]-C);
                else R[1][cnt[1]++]=modulo2(P[i]-C);
                }
            for(int l=0;l<2;++l){
                sort(R[l],R[l]+cnt[l]);
                int last=0;
                for(int k=1;k<cnt[l];++k)if( fabs(R[l][k]-R[l][last])<eps )continue;
                else ans=max(ans,k-last+2),last=k;
                ans=max(ans,cnt[l]-last+2);
                }            
            }
    if(n==1)ans=1;
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
