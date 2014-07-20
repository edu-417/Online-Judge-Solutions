#include<cstdio>
#include<algorithm>
using namespace std;
#define M 100000
int n,m,x,C;
int a[M+5];
inline int turnLeft(const int &start,const int &end,const int &mod){
    return (mod+start-end)%mod;    
    }
inline int turnRight(const int &start,const int &end,const int &mod){
    return (mod+end-start)%mod;    
    }
void doit(){
    scanf("%d%d%d",&n,&x,&m);
    for(int i=0;i<m;++i)scanf("%d",a+i);
    sort(a,a+m);m=unique(a,a+m)-a;
    int ans=n;
    int aux=turnLeft(x,a[0],n);
    int aux2=turnRight(a[0],a[m-1],n);
    if(a[m-1]<x && x<a[0]+n)aux2=0;
    if(a[m-1]<x+n && x<a[0])aux2=0;
    ans=min(ans,aux+aux2);
    for(int i=1;i<m;++i){
        int aux=turnLeft(x,a[i],n);
        int aux2=turnRight(a[i],a[i-1],n);
        if(a[i-1]<x && x<a[i])aux2=0;
        ans=min(ans,aux+aux2);
        }
    
    aux=turnRight(x,a[m-1],n);
    aux2=turnLeft(a[m-1],a[0],n);
    if(a[m-1]<x && x<a[0]+n)aux2=0;
    if(a[m-1]<x+n && x<a[0])aux2=0;
    ans=min(ans,aux+aux2);
    for(int i=0;i<m-1;++i){
        int aux=turnRight(x,a[i],n);
        int aux2=turnLeft(a[i],a[i+1],n);
        if(a[i]<x && x<a[i+1])aux2=0;
        ans=min(ans,aux+aux2);
        }
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
