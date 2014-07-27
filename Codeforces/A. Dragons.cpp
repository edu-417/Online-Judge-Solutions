#include<cstdio>
#include<algorithm>
using namespace std;
int s,n;
int x[1005],y[1005],ind[1005];
bool comp(int a,int b){
    return x[a]<x[b];
    }
int main(){
    scanf("%d%d",&s,&n);
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i),ind[i]=i;
    sort(ind,ind+n,comp);
    bool ans=true;
    for(int i=0;i<n;++i)if(s>x[ind[i]])s+=y[ind[i]];
    else ans=false;
    printf("%s\n",ans?"YES":"NO");
    }
