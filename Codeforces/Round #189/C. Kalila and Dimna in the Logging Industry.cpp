#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
long long dp[N+5];
int pos,size,n;
int a[N+5],b[N+5];

struct Line{
    long long m,b;
    Line(){}
    Line(long long _m, long long _b){
        m=_m;b=_b;
        }
    };
    
Line H[N+5];
    
bool checkTop(const Line &L){
    return !( (double)(L.b-H[size-2].b)/(H[size-2].m-L.m) > (double)(H[size-1].b-H[size-2].b)/(H[size-2].m-H[size-1].m) );
    }
    
void insert(const Line &L){
    for(;size>=2 && checkTop(L);--size)if(pos==size-1)--pos;
    H[size++]=L;
    }

long long evaluate(int idx,int x){
    return H[idx].m*x+H[idx].b;
    }
    
long long query(int x){
    long long ans=evaluate(pos,x);
    for(;pos+1<size;++pos){
        long long aux=evaluate(pos+1,x);
        if(ans<aux)break;
        ans=aux;
        }
    return ans;
    }
    
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)scanf("%d",b+i);
    pos=size=0;
    dp[0]=0;
    insert(Line(b[0],dp[0]));
    for(int i=1;i<n;++i){
        dp[i]=query(a[i]);
        insert(Line(b[i],dp[i]));
        }
    long long ans=dp[n-1];
    printf("%I64d\n",ans);
    }
