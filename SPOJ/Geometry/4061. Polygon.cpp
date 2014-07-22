#include<cstdio>
#include<complex>
#include<cstring>
#include<algorithm>
using namespace std;
//struct Point
typedef complex<int> Point;
#define X real()
#define Y imag()
//

#define Vector Point
#define oo (1<<10)
#define N 100
int n,x,y;
Point P[N+5];
int dp[N+5][N+5][N+5];
int modulo2(const Vector &A){return A.X*A.X+A.Y*A.Y;}

inline int cross(const Vector &A,const Vector &B){return A.X*B.Y-A.Y*B.X;}
bool cmp(const Point &A,const Point &B){
    if(cross(A,B)==0)return modulo2(A)<modulo2(B);
    return cross(A,B)>0;
    }

int f(int pos,int last,int last2){
    if(pos==n+1){
        if( cross(P[last2]-P[last],P[0]-P[last]) >0 )return 0;
        return -oo;
        }
    int &ret=dp[pos][last][last2];
    if(ret!=-1)return ret;
    int ans=f(pos+1,last,last2);
    if( cross( P[last2]-P[last],P[pos]-P[last] ) >0 )ans=max(ans,1+f(pos+1,last2,pos));
    return ret=ans;
    }
int main(){
    scanf("%d",&n);
    P[0]=Point(0,0);
    for(int i=1;i<=n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    sort(P+1,P+n+1,cmp);
    int ans=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)memset(dp[i][j],-1,sizeof(int)*(n+1));
    for(int i=1;i<n;++i)ans=max(ans,2+f(i+1,0,i));
    printf("%d\n",ans);
    }
