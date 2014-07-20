#include<cstdio>
#define P 10009
int n,k;
int factMod[P+5],inv[P+5];

int c(int n,int k){
    if(n<k)return 0;
    if(k==0 || k==n)return 1;
    return (long long)factMod[n]*inv[factMod[k]]*inv[factMod[n-k]]%P;
    }
    
//Teorema de Lucas
int cmb(int n,int k){
    int ans=1;
    while(n>0){
        int ni=n%P,ki=k%P;
        n/=P,k/=P;
        ans=ans*c(ni,ki)%P;
        }
    return ans;
    }

bool doit(){
    if(scanf("%d%d",&n,&k)!=2)return false;
    long long m=(long long)k*(k+1)/2;
    int ans;
    if(m>n)ans=0;
    else n-=m,ans=cmb(n+k-1,n);
    printf("%d\n",ans);
    return true;
    }
    
int main(){
    factMod[0]=1;
    for(int i=1;i<P;++i)factMod[i]=factMod[i-1]*i%P;
    inv[1]=1;
    for(int i=2;i<P;++i)inv[i]=(P-P/i)*inv[P%i]%P;
    while(1)if(!doit())break;
    }
