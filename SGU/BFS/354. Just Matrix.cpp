#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 600
int n;
int big[N+5], p[N+5],ind[N+5];
int top[N+5][N+5],left[N+5][N+5],in[N+5][N+5],a[N+5][N+5];
vector<int> L[N*N+5];
vector<int> order;
int tree[4*N+5];
bool cmp(int x,int y){
    return p[x]<p[y];
    }
int query(int idx){
    int ans=0;
    for(;idx>0;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
    }

int update(int idx,int val){
    for(;idx<=n;idx+=(idx&-idx))tree[idx]+=val;
    }
int bs(int x){
    int lo=1,hi=n;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(query(mid)>=x)hi=mid;
        else lo=mid+1;
        }
    return lo;
    }
int mapeo(int x,int y){
    return n*x+y;
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",top[i]+j);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",left[i]+j);
    bool valid=true;
    for(int j=0;j<n;++j)
        for(int i=0;i<n;++i)if(top[i][j]>i)valid=false;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(left[i][j]>j)valid=false;

    if(!valid){
        printf("0\n");return 0;
        }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)L[mapeo(i,j)].clear();
    for(int i=0;i<n;++i)memset(in[i],0,sizeof(int)*n);

    for(int j=0;j<n;++j){
        for(int i=0;i<n;++i)big[i]=top[i][j],ind[i]=i;
        for(int i=0;i<n;++i)update(i+1,1);
        for(int i=n-1;i>=0;--i){
            int pos=bs(i+1-big[i]);
            update(pos,-1);
            p[i]=pos-1;
            }
        sort(ind,ind+n,cmp);
        for(int i=0;i<n-1;++i)L[ mapeo( ind[i],j ) ].push_back( mapeo( ind[i+1],j ) ),++in[ ind[i+1] ][j];
        }


    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)big[j]=left[i][j],ind[j]=j;
        for(int j=0;j<n;++j)update(j+1,1);
        for(int j=n-1;j>=0;--j){
            int pos=bs(j+1-big[j]);
            update(pos,-1);
            p[j]=pos-1;
            }
        sort(ind,ind+n,cmp);
        for(int j=0;j<n-1;++j)L[ mapeo( i,ind[j] ) ].push_back( mapeo( i,ind[j+1] ) ),++in[i][ ind[j+1] ];
        }
    order.clear();
    queue<int> Q;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(in[i][j]==0)Q.push(mapeo(i,j));
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            int toX=to/n,toY=to%n;
            --in[toX][toY];
            if(in[toX][toY]>0)continue;
            Q.push(to);
            }
        order.push_back(u);
        }
    bool cycle=false;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(in[i][j]>0)cycle=true;
    if(cycle)printf("0\n");
    else{
        for(int i=0;i<n*n;++i)a[order[i]/n][order[i]%n]=i+1;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)printf("%s%d",j==0?"":" ",a[i][j]);
            printf("\n");
            }
        }
    }
