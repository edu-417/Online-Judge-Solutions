#include<cstdio>
#include<cstring>
#define N 50005
bool dp[N];
int a[105];
int n,L,C;
void doit(){
    scanf("%d",&n);
    L=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),L+=a[i];
    memset(dp,false,sizeof(bool)*(L+1));
    dp[0]=true;
    for(int i=0;i<n;++i)
        for(int j=L;j>=a[i];--j)
            dp[j]|=dp[j-a[i]];
    int ans=L;
    for(int i=L&1;i<=L;i+=2)
        if(dp[(L-i)/2] || dp[(L+i)/2]){
            ans=i;
            break;
            }
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
