#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 40
#define M 10
#define oo (1<<30)
int dp[N+5][M+5][(1<<10)+5][2];
int n,m,C;
char s[N+5][M+5];

int f(int x,int y,int mask,bool cover){
    if(x==n){
        if(mask==0)return 0;
        return oo;
        }
    if(y==m)return f(x+1,0,mask,false);
    int &ret=dp[x][y][mask][cover];
    if(ret>-1)return ret;
    if((mask>>y)&1 && s[x][y]!='*')return ret=oo;
    if((mask>>y)&1)return ret=1+f(x,y+1,mask^(1<<y),false) ;
    int ans=oo;
    if(s[x][y]=='*'){
        ans=1+f(x,y+1,mask,true) ;
        if(cover)ans=min( ans,f(x,y+1,mask,false) );
        else ans=min( ans,f(x,y+1,mask^(1<<y),false) );
        }
    else{
        ans=f(x,y+1,mask,false);
        }
    return ret=ans;
    }
    
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",s[i]);
    memset(dp,-1,sizeof(dp));
    int ans=f(0,0,0,false);
    printf("%d\n",ans);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
