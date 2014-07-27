#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y;
#define N 20
bool L[N+5][N+5];
long long dp[(1<<N)][N];
long long f(int mask,int end){
    if(mask==(1<<end))return 1;
    int last=mask&(-mask);
    int first;
    for(int i=0;i<n;++i)if((1<<i)==last)first=i;
    if(end==first)return 0;
    long long &ret=dp[mask][end];
    if(ret>-1)return ret;
    long long ans=0;
    for(int i=0;i<n;++i)
        if((mask>>i)&1 && L[i][end])ans+=f(mask^(1<<end),i);
    return ret=ans;
    }
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x][--y]=true,L[y][x]=true;
    long long ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<(1<<n);++i){
        int last=(i&(-i));
        int first;
        for(int j=0;j<n;++j)if((1<<j)==last)first=j;
        if(__builtin_popcount(i)>2)
            for(int j=0;j<n;++j)if((i>>j)&1 && L[first][j])ans+=f(i,j);
        }        
    ans>>=1;
    printf("%I64d\n",ans);
    }
