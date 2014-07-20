#include<cstdio>
long long n;
bool f(long long x){
    for(int i=0;;++i){
        if(x==1)return i&1;
        if(i&1)x=(x-1)/2+1;
        else x=(x-1)/9+1;
        }
    return false;
    }
bool doit(){
    if(scanf("%lld",&n)!=1)return false;
    printf("%s\n",f(n)? "Stan wins.":"Ollie wins.");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
