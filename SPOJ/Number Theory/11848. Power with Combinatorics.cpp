#include<cstdio>
#define MOD 1000000007
#define N 200000
int r[2],m[2];
int a,b,n,C;
long long B;
int fac[N+5];

int pow(int a,int n,int mod){
    int ans=1;
    for(;n>0;n>>=1){
        if(n&1)ans=(long long)ans*a%mod;
        a=(long long)a*a%mod;
        }
    return ans;
    }

int inv(int a,int mod){
    return pow(a,mod-2,mod);
    }
    
void doit(){
    scanf("%d%d%d",&a,&b,&n);
    r[1]=(long long)fac[n<<1]*inv((long long)fac[n]*fac[n]%m[1],m[1])%m[1];
    int exp=(B*r[1])%(MOD-1);
    int e=pow(exp,b,MOD-1);
    int ans=pow(a,e,MOD);
    printf("%d\n",ans);
    }
    
int main(){
    m[0]=2,m[1]=(MOD-1)>>1,
    fac[1]=1;
    B=(long long)inv(m[0],m[1])*m[0];
    for(int i=2;i<=N;++i)fac[i]=(long long)fac[i-1]*i%m[1];
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
