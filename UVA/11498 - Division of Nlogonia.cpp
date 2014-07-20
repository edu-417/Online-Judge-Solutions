#include<cstdio>

int n,x,y,dx,dy;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    scanf("%d%d",&dx,&dy);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        if(x==dx || y==dy)printf("divisa\n");
        else if(x>dx && y>dy)printf("NE\n");
        else if(x>dx)printf("SE\n");
        else if(x<dx && y>dy)printf("NO\n");
        else printf("SO\n");
        }
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
