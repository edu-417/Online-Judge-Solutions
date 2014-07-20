#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n,m,caso=0,C;
vector<int> S;
vector< int > d;
vector< bool > used;
bool b;
int bfs(){
    d.clear();
    used.clear();
    d.resize(1<<n , -1);
    used.resize( 1<<n , false );
    int source=(1<<n)-1;
    d[source]=0;
    used[source]=true;
    queue<int> Q;
    Q.push(source);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(size_t i=0;i<m;++i){
            int to= u^S[i];
            if(used[to])continue;
            used[to]=true;
            d[to]=d[u]+1;
            Q.push(to);
            }
        }
    return d[0];
    }
bool doit(){
    scanf("%d%d",&n,&m);
    S.resize(m);
    for(int i=0;i<m;++i){
        S[i]=0;
        for(int j=0;j<n;++j){
            scanf("%d",&b);
            S[i]<<=1;
            if(b)++S[i];
            }
        }
    int ans=bfs();
    if(ans==-1)printf("Case %d: IMPOSSIBLE",++caso);
    else printf("Case %d: %d",++caso,ans);
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
