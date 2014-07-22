#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define N 10000
int n,m,x,y,C;
vector<int> L[N+5];
vector<int> order;
int in[N+5];
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)L[i].clear();
    memset(in,0,sizeof(int)*n);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),++in[y];
    bool multiple=false,cycle=false;
    queue<int> Q;
    for(int i=0;i<n;++i)if(in[i]==0)Q.push(i);
    order.clear();
    while(!Q.empty()){
        if(Q.size()>1){
            multiple=true;
            }
        int u=Q.front();
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            --in[to];
            if(in[to]>0)continue;
            Q.push(to);
            }
        order.push_back(u);
        }
    for(int i=0;i<n;++i)if(in[i]>0)cycle=true;
    if(cycle)printf("recheck hints");
    else if(multiple)printf("missing hints");
    else for(int i=0;i<n;++i)printf("%s%d",i==0?"":" ",order[i]+1);
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
