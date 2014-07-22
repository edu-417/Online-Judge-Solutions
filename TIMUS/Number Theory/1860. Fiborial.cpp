#include<cstdio>
#define N 1000000
#define MOD 1000000007
 
int E[N+5], factor[N+5], F[N+5];
int n;

void criba(){ 
    for(int i=4;i<=N;i+=2)factor[i]=2;
    for(int i=3; i*i<=N; i+=2)
        if(!factor[i])for(int j = i*i; j <=N; j += i)if(!factor[j])factor[j] = i;
    }
 
 
void factPow(int n, int  a){ 
    for(;factor[n]>0; ){
        int e=0;
        int d=factor[n];
        for(;n%d==0;n/=d)++e;
        E[d]=( (long long)E[d]+ ( (long long)a*e ) )%MOD;
        }
    if(n>1)E[n]=(E[n]+a)%MOD;
}
 

void Fibonacci(){
    F[0]=F[1]= 1;
    for(int i=2;i<=N;++i)F[i]=(F[i-1]+F[i-2])%MOD; 
}

int main(){ 
    criba();
    Fibonacci();
    scanf("%d",&n);
    for(int i = n,j=0; i >=2; --i,++j)factPow(i,F[j]);
    int ans = 1;
    for(int i = 0; i <= n; i++)ans = ( (long long)ans * (E[i]+1) )%MOD;
    printf("%d\n", ans);
}
 
