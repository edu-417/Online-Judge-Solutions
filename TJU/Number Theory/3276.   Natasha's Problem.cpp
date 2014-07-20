#include<cstdio>
#include<cstring>
#define max(a,b) (a)>(b)? (a):(b)
#define N 30

unsigned int a[N+5];
int two[N+5];
int fermatPrime[]={3,5,17,257,65537};
int n;
int dp[N+5][(1<<5)+5];

int f(int pos,int mask){
    if(pos==n)return 0;
    int ret=dp[pos][mask];
    if(ret>-1)return ret;
    int ans=f(pos+1,mask);
    int cnt=0;
    int mask2=mask;
    unsigned int aux=a[pos];
    for(int i=0;i<5;++i)
        if( !( (mask>>i)&1 ) && aux%fermatPrime[i]==0 )aux/=fermatPrime[i],mask2^=(1<<i),cnt+=(1<<i);
    if(aux==(unsigned int)1)ans=max(ans,f(pos+1,mask2)+cnt+two[pos]);
    return ret=ans;
    }
    
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    bool one=false;
    for(int i=0;i<n;++i)scanf("%u",a+i);
    for(int i=0;i<n;++i)if(a[i]==1)one=true;
    for(int i=0;i<n;++i){
        two[i]=0;
        while(!(a[i]&1)){
            a[i]>>=1;++two[i];
            }
        if(two[i]>0)--two[i];
        }
    int ans=dp[0][0];
    if(ans==0 && !one)printf("No Solution\n");
    else printf("%d\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
