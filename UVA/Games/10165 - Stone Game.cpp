#include<cstdio>
int n,x;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    int ans=0;
    for(int i=0;i<n;++i)scanf("%d",&x),ans^=x;
    printf("%s\n",ans==0?"No":"Yes");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
