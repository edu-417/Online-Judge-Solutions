#include<cstdio>

bool b[10];
int n;
bool f(int x){
    while(1){
        if(x==0)break;
        int d=x%10;
        x/=10;
        if(b[d])return true;;
        }
    return false;
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    int x=n;
    while(1){
        if(x==0)break;
        int d=x%10;
        x/=10;
        b[d]=true;
        }
    int ans=0;
    for(long long i=1;i*i<=n;++i){
        if(n%i==0){
            if(f(i))++ans;
            if(i*i<n)if(f(n/i))++ans;
            }
        }
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
