#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 1000
int n,m,x,y;
vector<int> L[N+5];
int in[N+5];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),++in[y];
    queue<int> Q;
    for(int i=0;i<n;++i)scanf("%d",&x),Q.push(--x);
    bool valid=true;
    while(!Q.empty()){
        int u=Q.front();
        if(in[u]>0)valid=false;
        if(!valid)break;
        Q.pop();
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            --in[to];
            }
        }
    printf("%s\n",valid?"YES":"NO");
    }
