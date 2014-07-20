#include<cstdio>
#define N 10
int a[N+5];
int C;
void doit(){
    for(int i=0;i<N;++i)scanf("%d",a+i);
    int great=0,less=0;
    for(int i=0;i<N-1;++i)if(a[i]<a[i+1])great++;
    else if(a[i]>a[i+1])less--;
    if(less==0 || great==0)printf("Ordered\n");
    else printf("Unordered\n");
    }
int main(){
    scanf("%d",&C);
    printf("Lumberjacks:\n");
    for(int i=0;i<C;++i)doit();
    }
