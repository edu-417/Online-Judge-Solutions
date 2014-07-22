#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200000
int n,C;
int tree[N+5],a[N+5],ind[N+5],pos[N+5];
void update(int idx){
    for(;idx<=n;idx+=(idx&-idx))tree[idx]+=1;
    }
int query(int idx){
    int ans=0;
    for(;idx>0;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
    }
bool comp(int x,int y){
    return a[x]<a[y];
    }
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,comp);
    for(int i=0;i<n;++i)pos[ind[i]]=i;
    long long ans=0;
    memset(tree,0,sizeof(int)*(n+1));
    for(int i=n-1;i>=0;--i)ans+=query(pos[i]+1),update(pos[i]+1);
    printf("%lld\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
