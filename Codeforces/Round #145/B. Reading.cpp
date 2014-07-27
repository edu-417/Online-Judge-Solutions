#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
int a[N+5],ind[N+5];
int n,k;
bool comp(int x,int y){
    return a[x]<a[y];
    }
bool doit(){
    if(scanf("%d%d",&n,&k)!=2)return false;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,comp);
    printf("%d\n",a[ind[n-k]]);
    for(int i=0;i<k;++i)printf("%s%d",i==0? "":" ",ind[i+n-k]+1);
    printf("\n");
    return true;
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(1)if(!doit())break;
    }
