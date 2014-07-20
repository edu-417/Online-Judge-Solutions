#include<cstdio>
#include<algorithm>
using namespace std;
#define Vector Point

int n,m,C,caso=0;
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y){x=_x,y=_y;}
    };
    
Point P[20];
int mask[150];
int dp[125][(1<<17)];
Point operator -(const Point &P1,const Point &P2){return Point(P1.x-P2.x,P1.y-P2.y);}
int cross(const Vector &A,const Vector &B){return A.x*B.y-A.y*B.x;}

int area(const Point &A,const Point &B , const Point &C){
    return cross(B-A,C-A);
    }
void doit(){
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d%d",&x,&y),P[i]=Point(x,y);
    int ct=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            mask[ct]=0;
            for(int k=0;k<n;++k)
                if(area(P[i],P[j],P[k])==0)mask[ct]|=(1<<k);
            ++ct;
            }
        }
    for(int i=0;i<(1<<n);++i){
        int ones=0;
        for(int j=0;j<n;++j)if((i>>j)&1)++ones;
        if(ones>=m)dp[ct][i]=0;
        else dp[ct][i]=1<<30;
        }
    for(int i=ct-1;i>=0;--i)
        for(int j=0;j<(1<<n);++j)dp[i][j]=min(1+dp[i+1][j|mask[i]],dp[i+1][j]);
    if(caso!=0)printf("\n");
    printf("Case #%d:\n",++caso);
    printf("%d\n",dp[0][0]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
