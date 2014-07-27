#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100
int food[N+5];
int totFood;
int n;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&totFood);
    for(int i=0;i<n;++i)scanf("%d",food+i);
    for(int i=0;i<n;++i)food[i]*=(n-i);
    sort(food,food+n);
    int ans=0;
    for(int i=0;i<n;++i)if(food[i]<=totFood)++ans,totFood-=food[i];
    else break;
    printf("%d\n",ans);
    }
