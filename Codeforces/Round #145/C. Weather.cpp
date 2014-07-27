#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int n;
int a[N+5],pos[N+5],neg[N+5],zero[N+5];
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    if(a[0]>0)pos[0]=1,neg[0]=0,zero[0]=0;
    else if(a[0]<0)neg[0]=1,pos[0]=0,zero[0]=0;
    else zero[0]=1,pos[0]=0,neg[0]=0;
    for(int i=1;i<n;++i){
        pos[i]=pos[i-1],neg[i]=neg[i-1],zero[i]=zero[i-1];
        if(a[i]>0)pos[i]++;
        else if(a[i]<0)neg[i]++;
        else zero[i]++;
        }
    int ans=n;
    for(int i=0;i<n-1;++i){
        ans=min(ans,pos[i]+neg[n-1]-neg[i]+zero[n-1]);
        }
    printf("%d\n",ans);
    return true;
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(1)if(!doit())break;
    }

