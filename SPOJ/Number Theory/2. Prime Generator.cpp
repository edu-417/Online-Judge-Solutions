#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000
#define S 100000

bool prime[N+5],b[S+5];
int primo[N+5];
int n,m,cnt,C,caso=0;
void criba(){
    cnt=0;
    memset(prime,true,sizeof(bool)*(N+1));
    prime[0]=prime[1]=false;
    for(int i=2;i<=N;++i)
        if(prime[i]){
            primo[cnt++]=i;
            for(long long j=(long long)i*i;j<=N;j+=i)prime[j]=false;            
            }
    }
void doit(){
    if(caso>0)printf("\n");
    ++caso;
    scanf("%d%d",&m,&n);
    if(n<=N){
        for(int i=m;i<=n;++i)if(prime[i])printf("%d\n",i);
        return;
        }
    memset(b,true,sizeof(bool)*(S+1));
    int start=m;
    for(int i=0;i<cnt;++i){
        int ini=(start+primo[i]-1)/primo[i];
        int j=max(ini,2)*primo[i]-start;
        for(;j<=n-m;j+=primo[i])b[j]=false;
        }
    for(int i=m;i<=n;++i)if(b[i-start])printf("%d\n",i);
    }
int main(){
    criba();
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }

