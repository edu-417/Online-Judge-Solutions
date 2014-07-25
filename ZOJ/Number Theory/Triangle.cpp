#include<cstdio>
#define min(a,b) (a)<(b)? a:b
int C;
int pow(int a,int b,const int &mod){
    int ans=1;
    while(b>0){
        if(b&1)ans=((long long)ans*a)%mod;
        a=((long long)a*a)%mod;
        b>>=1;
        }
    return ans;
    }
int phi(int n){
    int ans=n;
    for(int i=2;i<=n/i;++i)
        if(n%i==0){
            while(n%i==0)n/=i;
            ans-=ans/i;
            }
    if(n>1)ans-=ans/n;
    return ans;
    }
void doit(){
    int a,z;
    scanf("%d%d",&a,&z);
    int f=phi(z);
    int l=f;
    for(int i=1;i<=f/i;++i)
        if(f%i==0){
            if(pow(a,i,z)==1)l=min(l,i);
            else if(pow(a,f/i,z)==1)l=min(l,f/i);
            }        
    printf("%lld\n",6LL*l+3);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
