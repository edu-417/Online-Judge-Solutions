#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 100
#define M 100
#define K 100
int C;
int dp[N+5][M+5][K+5];
int grundy(int n,int m,int k){
    int &ret=dp[n][m][k];
    if(ret>-1)return ret;
    set<int> S;
    if(n>1)S.insert(grundy(n-1,m,k));
    if(m>1)S.insert(grundy(n,m-1,k));
    if(n>k && m>k)S.insert(grundy(n-k,m-k,k));
    int ans=0;
    while(S.find(ans)!=S.end())++ans;
    return ret=ans;
    }
void doit(){
    int k,n,m;
    scanf("%d%d%d",&k,&n,&m);
    printf("%s\n",grundy(n,m,k)==0?"-":"+");
    }
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&C);
    //for(int i=0;i<C;++i)doit();
    
    for(int i=1;i<=4;++i)
        for(int j=1;j<=10;++j)
            for(int k=1;k<=10;++k)if(grundy(i,j,k)==0)printf("%d %d %d\n",i,j,k);
    }
