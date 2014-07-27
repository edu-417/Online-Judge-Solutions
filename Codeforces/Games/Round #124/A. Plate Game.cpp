#include<cstdio>
#define min(a,b) ((a)<(b)? (a):(b))

int a,b,r;
int main(){
    scanf("%d%d%d",&a,&b,&r);
    printf("%s\n",2*r>min(a,b)?"Second":"First");
    }
