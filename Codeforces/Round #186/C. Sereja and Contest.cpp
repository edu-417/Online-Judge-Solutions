#include<cstdio>
#define N 200000
int a[N+5];
int n ,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    long long ac=0;
    int nUsed=0;
    for(int i=2;i<=n;++i){
        long long tmp=0;
        long long aux=0;
        if(i>1){
            aux=(long long)a[i-1]*(i-2-nUsed);
            tmp=aux-(long long)(n-i)*(i-1-nUsed)*a[i];
            //printf("i: %d\n %lld %lld %lld\n",i,tmp,ac,tmp+ac);
            }
        if(tmp+ac>=k){
            ac+=aux;
            }
        else{
            ++nUsed;
            printf("%d\n",i);
            }
        }
    }
