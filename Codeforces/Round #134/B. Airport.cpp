#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[2000],b[2000];
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    for(int i=0;i<m;++i)scanf("%d",a+i),b[i]=a[i];
    int menor=0;
    int mayor=0;
    sort(a,a+m);
    int x=n;
    for(int i=0;i<m;++i)
        if(x>=a[i])x-=a[i],menor+=(a[i]*(a[i]+1)/2);
        else{
            menor+=(a[i]*(a[i]+1)/2),menor-=((a[i]-x)*(a[i]-x+1)/2);
            break;
            }
    for(int i=0;i<n;++i){
        sort(b,b+m);
        mayor+=b[m-1];
        --b[m-1];
        }
    printf("%d %d\n",mayor,menor);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
