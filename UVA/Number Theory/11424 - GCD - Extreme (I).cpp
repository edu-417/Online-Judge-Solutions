#include<cstdio>
#define N 200000

int phi[N+5];
long long s[N+5];
int n;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    printf("%lld\n",s[n]);
    return true;
    }

void criba(){
    for(int i=2;i<=N;++i)
        if(phi[i]==0)for(int j=i;j<=N;j+=i){
            if(phi[j]==0)phi[j]=j;
            phi[j]=phi[j]-phi[j]/i;
            }            
    }
void preprocess(){
    for(int i=2;i<=N;++i){
        s[i]=s[i-1];
        for(int j=1;j*j<=i;++j){
            if(i%j==0){
                s[i]+=(long long)phi[i/j]*j;
                if(j*j!=i)s[i]+=(long long)phi[j]*i/j;
                }
            }
        }
    }
int main(){
    criba();
    preprocess();
    while(1)if(!doit())break;
    }
