#include<cstdio>
long long n;
int main(){
    scanf("%lld",&n);
    int e=0;
    for(long long i=2;i<=n/i;++i){
        if(n%i==0){
            while(n%i==0)n/=i,++e;
            }
        }
    if(n>1)++e;
    if(e==2)printf("MARIAN\n");
    else printf("ANNE\n");
    }
