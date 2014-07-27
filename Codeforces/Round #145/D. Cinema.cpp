#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100
int m,k,n;
char c[100];
bool favorite[N+5];
int si[N+5],no[N+5],nose[N+5];
int best[N+5],poor[N+5];

bool zero(int x){
    for(int i=0;i<n;++i)
        if(i==x)continue;
        else if(poor[x]<best[i])return false;
    return true;
    }
bool two(int x){
    for(int i=0;i<n;++i)
        if(i==x)continue;
        else if(best[x]<poor[i])return false;
    return true;
    }
int f(int x){
    if(zero(x))return 0;
    if(two(x))return 2;
    return 1;
    }
bool doit(){
    int x,d;
    if(scanf("%d%d",&m,&k)!=2)return false;
    memset(favorite,false,sizeof(bool)*(m+1));
    for(int i=0;i<k;++i)scanf("%d",&x),favorite[x]=true;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",c);
        scanf("%d",&d);
        for(int j=0;j<d;++j){
            scanf("%d",&x);
            if(favorite[x])si[i]++;
            else if(x==0)nose[i]++;
            else no[i]++;
            }
        }
    for(int i=0;i<n;++i)
        if(k>=si[i]+nose[i])best[i]=si[i]+nose[i];
        else best[i]=k;

    int q=m-k;
    for(int i=0;i<n;++i)
        if(q>=no[i]+nose[i])poor[i]=si[i];
        else poor[i]=si[i]+nose[i]-(q-no[i]);

//    for(int i=0;i<n;++i)printf("%d %d %d %d %d\n",si[i],nose[i],no[i],best[i],poor[i]);
    for(int i=0;i<n;++i)printf("%d\n",f(i));
    return true;
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(1)if(!doit())break;
    }

