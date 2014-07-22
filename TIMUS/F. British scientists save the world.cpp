#include<cstdio>
int n,k,b,g;
int main(){
    scanf("%d%d",&n,&k);
    int ans=k-2;
    for(int i=0;i<n;++i)scanf("%d%d",&b,&g),ans+=b-g-2;
    if(ans>0)printf("%d\n",ans);
    else printf("Big Bang!\n");
    }
