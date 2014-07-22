#include<cstdio>
#define N 10000

int phi[N+5], s[N+5];
int n,C;
void criba(){
    phi[1]=1;
    for(int i=2;i<=N;++i)
        if(phi[i]==0)for(int j=i;j<=N;j+=i){
            if(phi[j]==0)phi[j]=j;
            phi[j]-=phi[j]/i;
            }
    }
    
void doit(){
    scanf("%d",&n);
    printf("%lld\n",(long long)s[n]*s[n]);
    }
    
int main(){
    criba();
    for(int i=1;i<=N;++i)s[i]=s[i-1]+phi[i];
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
