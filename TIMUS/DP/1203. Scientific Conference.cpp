#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define M 30005

int x[N],y[N],ind[N],_x[N],_y[N];
int n,m;
int dp[M];
bool compara(int ind1,int ind2){
    if(x[ind1]==x[ind2])return y[ind1]<y[ind2];
    return x[ind1]<x[ind2];
    }
bool doit(){
    if(scanf("%d",&m)!=1)return false;
    ++m;
    for(int i=1;i<m;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<m;++i)ind[i]=i;
    sort(ind,ind+m,compara);
    n=1;
    for(int i=1;i<m;++i)
        if(x[ind[i]]>_x[n-1])_x[n]=x[ind[i]],_y[n++]=y[ind[i]];
    _x[n]=M,_y[n]=M;

    int ans=1;
    for(int i=1;i<=n;++i)dp[i]=n;
    for(int i=1;i<n;++i){
        int lo=0,hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(_y[dp[mid]]<_x[i])lo=mid+1;
            else hi=mid;
            }
        if(_y[dp[lo-1]]<_x[i])
            if(_y[i]<_x[dp[lo]])dp[lo]=i;
            else if(_y[i]<_y[dp[lo]])dp[lo]=i;
        }
    for(int i=1;i<=n;++i)
        if(dp[i]==n){
            ans=i-1;
            break;
            }
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
