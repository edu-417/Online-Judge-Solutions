#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define N 100
int n,m,x,y,k,C,caso=0;
vector<int> L[N+5];
vector<int> order;
int in[N+5];
bool doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear();
    memset(in,0,sizeof(int)*n);
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&k);
        --x;
        for(int j=0;j<k;++j)scanf("%d",&y),L[--y].push_back(x),++in[x];
        }
    order.clear();
    priority_queue<int> Q;
    for(int i=0;i<n;++i)if(in[i]==0)Q.push(n-i);
    while(!Q.empty()){
        int u=Q.top();
        u=n-u;
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            --in[to];
            if(in[to]>0)continue;
            Q.push(n-to);
            }
        order.push_back(u);
        }
    if(caso>0)cout<<endl;
    ++caso;
    for(int i=0;i<n;++i)cout<<(i==0?"":" ")<<order[i]+1;
    cout<<endl;
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
