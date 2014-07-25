#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 15
#define R 100

bool dp[R+5][(1<<N)+5],used[R+5][(1<<N)+5];
int area[(1<<N)+5];
int a[N+5];
int n,r,c,caso;

bool f(int x,int mask){
    if(area[mask]%x>0)return false;
    if(__builtin_popcount(mask)==1)return true;
    bool &ret=dp[x][mask];
    if(used[x][mask])return ret;
    used[x][mask]=true;
    int y=area[mask]/x;
    bool ans=false;
    for(int mask2=(mask-1)&mask;mask2>0;mask2=(mask2-1)&mask){
        ans=ans || (f(x,mask2)&& f(x,mask^mask2));
        ans=ans || (f(y,mask2)&& f(y,mask^mask2));
        }
    return ret=ans;
    }
    
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    scanf("%d%d",&r,&c);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    
    for(int i=0;i<(1<<n);++i){
        area[i]=0;
        for(int j=0;j<n;++j)
            if((i>>j)&1)area[i]+=a[j];
        }
        
    if(r*c!=area[(1<<n)-1]){
        printf("Case %d: No\n",++caso);
        return true;
        }
        
    memset(used,false,sizeof(used));
    printf("Case %d: %s\n",++caso,f(r,(1<<n)-1)?"Yes":"No");
    return true;
    }
    
int main(){
    caso=0;
    while(1)if(!doit())break;
    }
