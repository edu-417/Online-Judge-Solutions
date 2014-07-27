#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int ind[N+5];
int x[N+5],y[N+5];
int n;
bool cmp(int a,int b){
    if(x[a]!=x[b])return x[a]<x[b];
    return y[a]<y[b];
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,cmp);
    int pos=ind[0];
    for(int i=1;i<n;++i)if( x[ ind[i] ] != x[ ind[i-1] ] )break;
    else pos=ind[i];
    bool ans=true;
    for(int i=0;i<n;++i)if(x[pos]<=x[i] && y[i]<=y[pos])continue;
    else ans=false;
    if(!ans)pos=-2;
    printf("%d\n",pos+1);
    }
