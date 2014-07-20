#include<cstdio>
#define N 1000000
int dp[N+5];
int f(int n){
    if(n==3)return 0;
    int &ret=dp[n];
    if(ret>0)return ret;
    int ans=0;
    if(n&1)ans=f(n-1)+(n/2-1)*(n/2);
    else ans=f(n-1)+(n/2-1)*(n/2-1);
    return ret=ans;
    }
int n,C;
void doit(){
    scanf("%d",&n);
    printf("%d\n",f(n));
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
