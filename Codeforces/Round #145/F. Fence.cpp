#include<cstdio>
#include<algorithm>
using namespace std;
int h[205],s[205];
int dp[205][40005][2];
int n,a,b;
void doit(){
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    for(int i=0;i<n;++i)scanf("%d",h+i);
    s[0]=h[0];
    for(int i=1;i<n;++i)s[i]=s[i-1]+h[i];
    for(int i=n-1;i>=1;--i)
        for(int j=0;j<=a;++j)
            for(int k=0;k<2;++k){
                dp[i][j][k]=-1;
                int d=b-(s[i-1]-(a-j));
                if(j>=h[i]){
                    int aux=dp[i+1][j-h[i]][0];
                    if(aux!=-1)if(k==1)aux+=min(h[i],h[i-1]);
                    if(dp[i][j][k]==-1)dp[i][j][k]=aux;
                    }
                if(d>=0 && d>=h[i]){
                    int aux=dp[i+1][j][1];
                    if(aux!=-1)if(k==0)aux+=min(h[i],h[i-1]);
                    if(dp[i][j][k]==-1)dp[i][j][k]=aux;
                    else if(aux!=-1)dp[i][j][k]=min(dp[i][j][k],aux);
                    }
                }
    int ans=-1;
    if(a>=h[0])ans=dp[1][a-h[0]][0];
    if(b>=h[0])if(ans==-1)ans=dp[1][a][1];
    else if(dp[1][a][1]!=-1)ans=min(ans,dp[1][a][1]);
    printf("%d\n",ans);
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    doit();
    }
