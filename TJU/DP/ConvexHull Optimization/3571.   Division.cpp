#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000
#define M 5000
int a[N+5],sq[N+5];
int dp[2][N+5];
int size,pos,n,m,C,caso;

struct Line{
    int m,b;
    Line(){}
    Line(int _m, int _b){
        m=_m;b=_b;
        }
    };
    
Line H[N+5];
    
inline bool checkTop(const Line &L){
    return (long long)(L.b-H[size-2].b)*(H[size-2].m-H[size-1].m)<=(long long)(H[size-1].b-H[size-2].b)*(H[size-2].m-L.m);
    }
    
inline void insert(const Line &L){
    for(;size>=2 && checkTop(L);--size)if(pos==size-1)--pos;
    H[size++]=L;
    }

inline int evaluate(int idx,int x){
    return H[idx].m*x+H[idx].b;
    }
    
inline int query(int x){
    int ans=evaluate(pos,x);
    for(;pos+1<size;++pos){
        int aux=evaluate(pos+1,x);
        if(ans<aux)break;
        ans=aux;
        }
    return ans;
    }
    
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;++i)sq[i]=a[i]*a[i];
    for(int i=0;i<n;++i)dp[1][i]=(a[i]-a[0])*(a[i]-a[0]);
    for(int k=1,r=0;k<m;++k,r^=1){
        size=0,pos=0;
        for(int i=0;i<n;++i){
            if(i<=k)dp[r][k]=0;
            else{
                int q=query(a[i]);
                dp[r][i]=sq[i]+q;
                }
            if(i<n-1){
                int b=sq[i+1]+dp[r^1][i];
                int m=-(a[i+1]<<1);
                insert( Line(m,b) );
                }
            }
        }
    int ans;
    if(n==0)ans=0;
    else ans=dp[m&1][n-1];
    printf("Case %d: %d\n",++caso,ans);
    }
    
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
