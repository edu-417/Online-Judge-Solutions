#include<cstdio>
int n,k;
int e[105];
int c(int n,int k){
    if(k>n-k)k=n-k;
    long long ans=1;
    for(int i=0;i<k;++i)ans*=(n-i),ans/=(i+1);
    return (int)ans;
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    scanf("%d",&k);
    for(int i=0;i<k;++i)scanf("%d",e+i);
    long long ans=1;
    for(int i=0;i<k-1;++i)ans*=c(n,n-e[i]),n-=e[i];
    printf("%d\n",(int)ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
