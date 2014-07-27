#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000

int n,m,a,b,type,x;
int A[N+5];
int tree[4*N+5][25];
int Xor[4*N+5];
inline int left(int node){
    return node<<1;    
    }

inline int right(int node){
    return (node<<1)^1;
    }
    
inline void push(int node,int tl,int tr){
    if(tl==tr){
        for(int i=0;i<20;++i)
            if((Xor[node]>>i)&1)tree[node][i]^=1;
        }
    else{
        Xor[left(node)]^=Xor[node];
        Xor[right(node)]^=Xor[node];
        for(int i=0;i<20;++i)
            if((Xor[node]>>i)&1)tree[node][i]=tr-tl+1-tree[node][i];
        }
    Xor[node]=0;
    }
    
void update(int node,int tl,int tr,int l,int r,int x){
    push(node,tl,tr);
    if(l>r)return ;
    if(tl==l && tr==r){
        Xor[node]^=x;
        push(node,tl,tr);
        }
    else{
        push(node,tl,tr);
        int tm=tl+((tr-tl)>>1);
        update(left(node),tl,tm,l,min(tm,r),x);
        update(right(node),tm+1,tr,max(tm+1,l),r,x);
        for(int i=0;i<20;++i)tree[node][i]=tree[left(node)][i]+tree[right(node)][i];
        }
    }

long long query(int node,int tl,int tr,int l,int r){
    push(node,tl,tr);
    if(l>r)return 0;
    if(tl==l && tr==r){
        push(node,tl,tr);
        long long ans=0;
        for(int i=0;i<20;++i)ans+=(1LL<<i)*tree[node][i];
        return ans;
        }
    push(node,tl,tr);
    int tm=tl+((tr-tl)>>1);
    return query(left(node),tl,tm,l,min(tm,r))+query(right(node),tm+1,tr,max(tm+1,l),r);
    }

void build(int node,int tl,int tr){
    if(tl==tr){
        for(int i=0;i<20;++i)if((A[tl]>>i)&1)tree[node][i]=1;
        return ;
        }
    int tm=tl+((tr-tl)>>1);
    build(left(node),tl,tm);
    build(right(node),tm+1,tr);
    for(int i=0;i<20;++i)tree[node][i]=tree[left(node)][i]+tree[right(node)][i];
    }
    
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",A+i);
    build(1,0,n-1);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&type,&a,&b);
        if(type==2){
            scanf("%d",&x);
            update(1,0,n-1,--a,--b,x);
            }
        else{
            printf("%I64d\n",query(1,0,n-1,--a,--b));
            }
        }
    }
