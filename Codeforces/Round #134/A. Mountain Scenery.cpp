#include<cstdio>

int n,k;
int a[500];
bool doit(){
    if(scanf("%d%d",&n,&k)!=2)return false;
    for(int i=0;i<2*n+1;++i)scanf("%d",a+i);
    for(int i=1,j=0;i<2*n+1 && j<k;i+=2)
        if(a[i]-1>a[i-1] && a[i]-1>a[i+1])j++,--a[i];
    for(int i=0;i<2*n+1;++i)printf("%d ",a[i]);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
