#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000000
#define oo 1<<30
int ind[3];
char c[3][N+5];
int border[N+5];
int f(int x,int y){
    int n=strlen(c[y]);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(j>0 && c[y][i]!=c[y][j])j=border[j-1];
        if(c[y][i]==c[y][j])++j;
        border[i]=j;
        }
    int m=strlen(c[x]);
    int j=0;
    for(int i=0;i<m;++i){
        while(j>0 && c[x][i]!=c[y][j])j=border[j-1];
        if(c[x][i]==c[y][j])++j;
        }
    return n+m-j;
    }
bool in(int x,int y){
    int n=strlen(c[x]);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(j>0 && c[x][i]!=c[x][j])j=border[j-1];
        if(c[x][i]==c[x][j])++j;
        }
    int j=0;
    for(int i=0;c[y][i];++i){
        while(j>0 && c[y][i]!=c[x][j])j=border[j-1];
        if(c[y][i]==c[x][j])++j;
        if(j==n)return true;
        }
    return false;
    }
bool doit(){
    if(scanf("%s",c[0])!=1)return false;
    scanf("%s%s",c[1],c[2]);
    bool b[3];
    for(int i=0;i<3;++i){
        b[i]=true;
        for(int j=0;j<3;++j)
            if(i==j)continue;
            else if(in(i,j)){
                b[i]=false;break;
                }
        }
    int ct=0;
    for(int i=0;i<3;++i)if(b[i])++ct;
    if(ct==1){
        for(int i=0;i<3;++i)if(b[i])printf("%d\n",strlen(c[i]));
        return true;
        }
    if(ct==2){
        int pos[2];
        int q=0;
        for(int i=0;i<3;++i)if(b[i])pos[q++]=i;
        int ans=min( f( pos[0],pos[1] ), f( pos[1],pos[0] ) );
        printf("%d\n",ans);
        return true;
        }
    for(int i=0;i<3;++i)ind[i]=i;
    int ans=oo;
    do{
        ans=min(  ans , f( ind[0] , ind[1] )  +  f( ind[1] , ind[2] ) - (int)strlen( c[ ind[1] ] ) );
        }while( next_permutation(ind,ind+3) );
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
