#include<cstdio>
int x,y,_x,_y;
bool doit(){
    scanf("%d%d%d%d",&x,&y,&_x,&_y);
    if(x==0 && y==0 && _x==0 && _y==0)return false;
    if(x==_x && y==_y)printf("0\n");
    else if(x==_x || y==_y)printf("1\n");
    else if(x+y==_x+_y || x-y==_x-_y)printf("1\n");
    else printf("2\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
