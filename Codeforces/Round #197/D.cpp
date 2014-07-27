#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define N 18
int tree[4*(1<<N)+5];

int n,m,x,y;
int a[(1<<N)+5];

inline int Left(int node){
    return (node<<1);
    }

inline int Right(int node){
    return (Left(node)^1);
    }
void build(int node,int l,int r,bool level){
    if(l==r)tree[node]=a[l];
    else{
        int m=l+((r-l)>>1);
        build(Left(node),l,m,level^1);
        build(Right(node),m+1,r,level^1);
        if(!level)tree[node]=tree[Left(node)]^tree[Right(node)];
        else tree[node]=tree[Left(node)]|tree[Right(node)];
        }
    }

void update(int node,int l,int r,int pos,int val,bool level){
    if(l==r)tree[node]=val;
    else{
        int m=l+((r-l)>>1);
        if(pos<=m)update(Left(node),l,m,pos,val,level^1);
        else update(Right(node),m+1,r,pos,val,level^1);
        if(!level)tree[node]=tree[Left(node)]^tree[Right(node)];
        else tree[node]=tree[Left(node)]|tree[Right(node)];
        }
    }
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    for(int i=0;i<(1<<n);++i)scanf("%d",a+i);
    if(n&1)build(1,0,(1<<n)-1,1);
    else build(1,0,(1<<n)-1,0);
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        if(n&1)update(1,0,(1<<n)-1,--x,y,1);
        else update(1,0,(1<<n)-1,--x,y,0);
        printf("%d\n",tree[1]);
        }
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
