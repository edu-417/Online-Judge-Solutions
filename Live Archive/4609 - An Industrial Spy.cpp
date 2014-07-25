#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10000000
using namespace std;
char s[10];
int C;
bool prime[N+5];
bool form[N+5];

void criba(){
    memset(prime,true,sizeof(bool)*N);
    prime[0]=prime[1]=false;
    for(int i=4;i<=N;i+=2)prime[i]=false;
    for(int i=3;i*i<=N;i+=2)
        for(int j=i*i;j<=N;j+=i)prime[j]=false;
    }
void doit(){
    scanf("%s",&s);
    int n=strlen(s);
    sort(s,s+n);
    memset(form,false,sizeof(false)*N);
    do{
        for(int i=0;i<(1<<n);++i){
            int num=0;
            for(int j=0;j<n;++j)if((i>>j)&1)num=num*10+s[j]-'0';
            if(prime[num])form[num]=true;
            }
        }while(next_permutation(s,s+n));
    int ans=0;
    for(int i=0;i<N;++i)if(prime[i] && form[i])++ans;
    printf("%d\n",ans);
    }
int main(){
    criba();
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
