#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define alphabet 30
#define N 100
int u,v,a,b,c,d,n;
int x[alphabet+5];
int m[N+5][N+5];
int dirV;
bool up;
void move(){
    if(u==0){
        v+=dirV;
        if(v==a+c){
            ++u;
            v=a+c-1;
            up=false;
            dirV=-dirV;
            }
        }
    else if(up){
        v+=dirV;
        if(v==-1)v=0,--u,dirV=-dirV;
        else if(v==a)v=a-1,--u,dirV=-dirV;
        }
    else{
        v+=dirV;
        if(v==a-1)v=a,++u,dirV=-dirV;
        else if(v==a+c)v=a+c-1,++u,dirV=-dirV;
        }
    }
int main(){
    memset(m,-1,sizeof(m));
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    for(int i=0;i<n;++i)scanf("%d",x+i);
    u=b-1;
    up=true;
    if(b&1)v=0,dirV=1;
    else v=a-1,dirV=-1;
    printf("YES\n");
    for(int i=0;i<n;++i)
        for(int j=0;j<x[i];++j){
            m[u][v]=i;
            move();
            }
    for(int i=0;i<max(b,d);++i){
        for(int j=0;j<a+c;++j)if(m[i][j]==-1)printf(".");
        else printf("%c",m[i][j]+'a');
        printf("\n");
        } 
    }
