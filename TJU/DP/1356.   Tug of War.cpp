#include<cstdio>

#define N 45005
bool dp[55][N];
int a[105];
int n,L;

int main(){
    scanf("%d",&n);
    int L=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),L+=a[i];
    
    dp[0][0]=true;
    for(int i=0;i<n;++i)
        for(int j=n/2;j>=1;--j)
            for(int k=a[i];k<=L;++k)
                dp[j][k]|=dp[j-1][k-a[i]];
    int dif=L;
    for(int i=L&1;i<=L;i+=2)
        if(dp[n/2][(L-i)/2] || dp[n/2][(L+i)/2]){
            dif=i;
            break;
            }
    printf("%d %d\n",(L-dif)/2,(L+dif)/2);
    }
