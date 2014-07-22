#include<cstdio>
#include<algorithm>
using namespace std;
#define N 50000
int a[N+5];
struct data{
    int pref,suf,sum,ans;
    data(){};
    data(int value){
        pref=suf=sum=ans=value;
        }
    };

data combine(const data &left,const data &right){
    data aux;
    aux.pref=max(left.pref,left.sum+right.pref);
    aux.suf=max(right.suf,right.sum+left.suf);
    aux.sum=left.sum+right.sum;
    aux.ans=max(max(right.ans,left.ans),left.suf+right.pref);
    return aux;
    }
data tree[4*N+5];
void build(int node,int left,int right){
    if(left==right)tree[node]=data(a[left]);
    else{
        int m=left+((right-left)>>1);
        build(node<<1,left,m);
        build((node<<1)^1,m+1,right);
        tree[node]=combine(tree[node<<1],tree[(node<<1)^1]);
        }
    }

data query(int node,int left,int right,int l,int r){
    if(left==l && right==r)return tree[node];
    int m=left+((right-left)>>1);
    if(r<=m)return query(node<<1,left,m,l,r);
    if(l>m)return query((node<<1)^1,m+1,right,l,r);
    data L=query(node<<1,left,m,l,m);
    data R=query((node<<1)^1,m+1,right,m+1,r);
    return combine(L,R);
    }

int n,x,y,m;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    build(1,0,n-1);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        data aux=query(1,0,n-1,--x,--y);
        printf("%d\n",aux.ans);
        }
    }
