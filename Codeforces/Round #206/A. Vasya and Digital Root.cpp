#include<cstdio>

int k,d;
int main(){
    scanf("%d%d",&k,&d);
    if(d==0 && k>1){
        printf("No solution\n");
        }
    else{
        for(int i=1;i<k;++i)printf("9");
        printf("%d\n",d);
        }
    
    }
