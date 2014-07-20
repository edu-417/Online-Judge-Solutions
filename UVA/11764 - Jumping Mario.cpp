#include<cstdio>
int n,C,caso,x,y;
void doit(){
    scanf("%d%d",&n,&x);
    int high=0,low=0;
    for(int i=1;i<n;++i){
        scanf("%d",&y);
        if(x<y)++high;
        else if(x>y)++low;
        x=y;
        }
    printf("Case %d: %d %d\n",++caso,high,low);
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }

