#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10000000
int n,C;
int tree[N+5],a[N+5];
void update(int idx){
    for(;idx<=N;idx+=(idx&-idx))tree[idx]+=1;
    }
int query(int idx){
    int ans=0;
    for(;idx>0;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
    }
    
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    long long ans=0;
    memset(tree,0,sizeof(tree));
    for(int i=n-1;i>=0;--i)ans+=query(a[i]),update(a[i]);
    printf("%lld\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
