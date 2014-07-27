#include<cstdio>
int n;
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    printf("%d",n);
    for(int i=0;i<n-1;++i)printf(" %d",i+1);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
