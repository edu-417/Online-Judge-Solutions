#include<cstdio>
#include<cstring>
#define mod 1000000007
#define N 100000
char s[N+4];
int k;

int pow(int a,long long n){
    long long ans=1;
    while(n>0){
        if(n&1)ans=(ans*a)%mod;
        a=((long long)a*a)%mod;
        n>>=1;
        }
    return ans;
    }
    
int main(){
    scanf("%s%d",s,&k);
    int n=strlen(s);
    int ans=0;
    for(int i=0;s[i];++i)if(s[i]=='0' || s[i]=='5')ans=(ans+((mod+pow(2,(long long)i+(long long)k*n)-pow(2,i))%mod))%mod;
    int inv=(mod+pow(2,n)-1)%mod;
    inv=pow(inv,mod-2);
    ans=((long long)ans*inv)%mod;
    printf("%d\n",ans);
    }
