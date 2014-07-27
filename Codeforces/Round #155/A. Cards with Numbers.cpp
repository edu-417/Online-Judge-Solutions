#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300000
int a[2*N+5];
int ind[2*N+5];
int n;
bool cmp(int x,int y){
    return a[x]<a[y];
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<2*n;++i)scanf("%d",a+i);
    for(int i=0;i<2*n;++i)ind[i]=i;
    sort(ind,ind+2*n,cmp);
    bool val=true;
    for(int i=0;i<2*n;i+=2)if(a[ind[i]]!=a[ind[i+1]])val=false;
    if(!val)printf("-1\n");
    else{
        for(int i=0;i<2*n;i+=2)printf("%d %d\n",ind[i]+1,ind[i+1]+1);
        }
    }
