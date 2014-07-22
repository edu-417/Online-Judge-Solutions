#include<cstdio>
#define N 1000000

int f[N+5];
int a,b;
void criba(){
    for(int i=2;i*i<=N;++i)
        if(f[i]==0)for(int j=i*i;j<=N;j+=i)if(f[j]==0)f[j]=i;
    }

int sumDiv(int n){
    int ans=1;
    while(f[n]>0){
        int aux=1,p=f[n],sum=1;
        while(n%p==0){
            aux*=p;
            sum+=aux;
            n/=p;
            }
        ans*=sum;
        }
    if(n>1)ans*=(n+1);
    return ans;
    }
int main(){
    criba();
    scanf("%d%d",&a,&b);
    int n=sumDiv(a)-a,d=a;
    for(int i=a+1;i<=b;++i){
        int _n=sumDiv(i)-i,_d=i;
        if((long long)_n*d<(long long)n*_d)n=_n,d=_d;
        }
    printf("%d\n",d);
    }
