#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    int ans=n*(n+1)/2;
    if(ans&1)printf("grimy\n");
    else printf("black\n");
    }
