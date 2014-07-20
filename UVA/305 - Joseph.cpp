#include<cstdio>

int a[]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int n;

bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    printf("%d\n",a[--n]);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }


/*bool g(int n,int k){
    int aux=0;
    for(int i=0;i<n;++i){
        aux=(aux+k-1)%(2*n-i);
        if(aux<n)return false;
        }
    return true;
    }
int f(int n){
    for(int i=n+1;;++i)if(g(n,i))return i;
    return 0;
    }
int main(){
    printf("a[]={");
    for(int i=1;i<14;++i)printf("%s%d",i==1?"":",",f(i));
    printf("\n");
    }*/
