#include<cstdio>

//0-index
//O(n);
int joseph(int n,int k){
    if(n==1)return 0;
    return (joseph(n-1,k)+k)%n 
    //dp[1]=0;
    //for(int i=2;i<=n;++i)dp[i]=(dp[i-1]+k)%i
    //dp[n];
    int ans=0;
    for(int i=1;i<=n;++i)ans=(ans+k)%i;
    return ans
    }

//O(klogn)
int joseph(int n,int k){
    if(n==1)return 0;
    if(k==1)return n-1;
    if(k>n)return (joseph(n-1,k)+k)%n;
    int cnt=n/k;
    int ans=joseph(n-cnt,k);
    ans-=n%k;
    if(ans<0)ans+=n;
    else ans+=ans/(k-1);
    return ans;
    }
int main(){
    }
