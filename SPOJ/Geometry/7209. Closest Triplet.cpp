#include<cstdio>
#include<cmath>
#include<complex>
#include<algorithm>
using namespace std;
//struct Point
typedef complex<int> Point;
#define X real()
#define Y imag() 
//
#define Vector Point

double modulo(const Vector &A){return sqrt((long long)A.X*A.X+(long long)A.Y*A.Y);}
bool cmpX(const Point &A,const Point &B){
    if(A.X==B.X)return A.Y<B.Y;
    return A.X<B.X;
    }
    
bool cmpY(const Point &A,const Point &B){
    if(A.Y==B.Y)return A.X<B.X;
    return A.Y<B.Y;
    }
#define N 3000
Point P[N+5];
int n,x,y;
double ans;

void closestPair(int left,int right){
    if(right-left<3){
        for(int i=left;i<=right;++i)
            for(int j=i+1;j<=right;++j)
                for(int k=j+1;k<=right;++k){
                    double aux=0;
                    aux+=modulo(P[i]-P[j]);
                    aux+=modulo(P[j]-P[k]);
                    aux+=modulo(P[k]-P[i]);
                    ans=min(ans,aux);
                    }
        sort(P+left,P+right+1,cmpY);
        return;
        }
    
    int mid=left+((right-left)>>1);
    int midX=P[mid].X;
    closestPair(left,mid),closestPair(mid+1,right);
    
    static Point t[N+5];
    merge(P+left,P+mid+1,P+mid+1,P+right+1,t,cmpY);
    copy(t,t+right-left+1,P+left);
    
    int size=0;
    for(int i=left;i<=right;++i)
            if(abs(P[i].X-midX)<ans*0.5){
            for(int j=size-1;j>=0 && P[i].Y-t[j].Y<ans*0.5;--j)
                for(int k=j-1;k>=0 && P[i].Y-t[k].Y<ans*0.5;--k){
                    double aux=0;
                    aux+=modulo(P[i]-t[j]);
                    aux+=modulo(t[j]-t[k]);
                    aux+=modulo(P[i]-t[k]);
                    ans=min(ans,aux);
                    }
            t[size++]=P[i];
            }
    }
    
bool doit(){
    scanf("%d",&n);
    if(n==-1)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    sort(P,P+n,cmpX);
    ans=1e20;
    closestPair(0,n-1);
    printf("%.3lf\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
