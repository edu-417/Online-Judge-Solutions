#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define N 100000
int n1,n2,d,x,y;
vector<int>L[N+5];
int in[N+5];
bool doit(){
    scanf("%d%d%d",&n1,&n2,&d);
    if(n1==0 && n2==0 && d==0)return false;
    for(int i=0;i<n1+n2;++i)L[i].clear();
    //memset(in,0,sizeof(int)*(n1+n2));
    for(int i=0;i<d;++i)scanf("%d%d",&y,&x),L[--x].push_back(--y),++in[y];
    int ans[2];
    ans[0]=ans[1]=1;
    for(int k=0;k<2;++k){
        queue<int> Q[2];
        int disk=k;
        for(int i=0;i<n1;++i)if(in[i]==0)Q[0].push(i);
        for(int i=n1;i<n1+n2;++i)if(in[i]==0)Q[1].push(i);
        while(!Q[0].empty() || !Q[1].empty()){
            if(Q[disk].empty())++ans[k],disk^=1;
            int u=Q[disk].front();
            Q[disk].pop();
            for(int i=0;i<L[u].size();++i){
                int to=L[u][i];
                --in[to];
                if(in[to]>0)continue;
                if(to<n1)Q[0].push(to);
                else Q[1].push(to);
                }
            }
        if(k==0){
            //memset(in,0,sizeof(int)*(n1+n2));
            for(int i=0;i<n1+n2;++i)
                for(int j=0;j<L[i].size();++j){
                    int to=L[i][j];
                    ++in[to];
                    }
            }
        ++ans[k];
        }
    printf("%d\n",min(ans[0],ans[1]));
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
