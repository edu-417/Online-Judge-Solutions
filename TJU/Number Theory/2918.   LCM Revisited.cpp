#include<cstdio>
int n;
#define N 100000
int phi(int n){
    int ans=n;
    for(int i=2;(unsigned int)i*i<=n;++i){
        if(n%i==0){
            while(n%i==0)n/=i;
            ans-=ans/i;
            }
        }
    if(n>1)ans-=ans/n;
    return ans;
    }

int numDiv(int n){
    int ans=0;
    for(int i=1;(unsigned int)i*i<=n;++i){
        if(n%i==0)if(i*i==n)++ans;
        else ans+=2;
        }
    return ans;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    int ans=n-phi(n)-numDiv(n)+1;
    printf("%d\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
