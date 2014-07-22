#include<cstdio>

#define MAX_X 32001
#define N 15000

int n,x,y;
int tree[MAX_X+5];
int level[N+5];
void update(int idx,int val){
    for(;idx<=MAX_X;idx+=(idx&-idx))tree[idx]+=val;
    }
int query(int idx){
    int ans=0;
    for(;idx>0;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
    }
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        level[query(x+1)]++;
        update(x+1,1);
        }
    for(int i=0;i<n;++i)printf("%d\n",level[i]);
    }
int main(){
    doit();
    }
