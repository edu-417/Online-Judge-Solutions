#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int button[15],d[10005];
int source,sink,n,caso=0;
bool doit(){
    memset(d,-1,sizeof(d));
    scanf("%d%d%d",&source,&sink,&n);
    if(source==0 && sink==0 && n==0)return false;
    for(int i=0;i<n;++i)scanf("%d",button+i);
    queue<int> Q;
    Q.push(source);
    d[source]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<n;++i){
            int to=u+button[i];
            if(to>=10000)to-=10000;
            if(d[to]!=-1)continue;
            d[to]=d[u]+1;
            Q.push(to);
            }
        }
    if(d[sink]==-1)printf("Case %d: Permanently Locked\n",++caso);
    else printf("Case %d: %d\n",++caso,d[sink]);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
