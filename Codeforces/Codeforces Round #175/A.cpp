#include<cstdio>
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-k-1;++i)printf("%d ",i+1);
    for(int i=n-k-1,j=n;i<n;++i,--j)printf("%d ",j);
    printf("\n");
    }
