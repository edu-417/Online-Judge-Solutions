#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n<38){
        if(n==0 || n==4 || n==8 || n==14 || n==20 || n==24 || n==28 || n==34)printf("Black\n");
        else printf("White\n");
        }
    else{
        n=(n-38)%34;
        if(n==0 || n==4 || n==16 || n==20 || n==24)printf("Black\n");
        else printf("White\n");
        }
    }
