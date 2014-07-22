#include<cstdio>
#define N 1000

int f(int x){
    for(int i=1;i<=x;++i)if(x/i==x/(i+1))return i;
    return x+1;
    }
int main(){
    for(int i=1;i<=N;++i)printf("%d\n",f(i));
    }
