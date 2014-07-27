#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
int n,timer,cnt;
int t[N+5],c[N+5];
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d%d",t+i,c+i);
    timer=t[0],cnt=c[0];
    int size=cnt;
    for(int i=1;i<n;++i){
        int dif=t[i]-timer;
        cnt=max(0,cnt-dif);
        cnt+=c[i];
        size=max(size,cnt);
        timer=t[i];
        }
    timer+=cnt;
    printf("%d %d\n",timer,size);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
