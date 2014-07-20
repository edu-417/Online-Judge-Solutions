#include<cstdio>

int n,m,x,y,_x,_y,C;

bool isValid(int x,int y){
    return x>0 && y>0 && x<=n && y<=n;
    }
void doit(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;++i){
        scanf("%d%d%d%d",&x,&y,&_x,&_y);
        int ans=-1;
        if(x==_x && y==_y)ans=0;
        else if(x+y==_x+_y || x-y==_x-_y)ans=1;
        else{
            int u=(-x-y+_x+_y);
            int v=(x-y-_x+_y);
            if(!(u&1) && !(v&1) && ( isValid(x+u/2,y+u/2) || isValid(x-v/2,y+v/2) ) )ans=2;
            }
        if(ans==-1)printf("no move\n");
        else printf("%d\n",ans);
        }
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
