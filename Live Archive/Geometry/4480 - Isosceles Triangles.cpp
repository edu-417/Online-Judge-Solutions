#include<cstdio>
#include<algorithm>
#include<complex>
using namespace std;
//struct Point
typedef complex <int> Point;
#define x real()
#define y imag()
//
#define N 1000
Point P[N+5];
int _x,_y,n;
long long d[N+5][N+5];
long long mod2(const Point &A){return (long long)A.x*A.x+(long long)A.y*A.y;}
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d%d",&_x,&_y),P[i]=Point(_x,_y);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)d[i][j]=mod2(P[i]-P[j]);
    for(int i=0;i<n;++i)sort(d[i],d[i]+n);
    int ans=0;
    for(int i=0;i<n;++i){
        int cnt=1;
        for(int j=1;j<n;++j)if(d[i][j]==d[i][j-1])++cnt;
        else ans+=(cnt*(cnt-1)/2),cnt=1;
        ans+=(cnt*(cnt-1)/2);
        }
    printf("%d\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
