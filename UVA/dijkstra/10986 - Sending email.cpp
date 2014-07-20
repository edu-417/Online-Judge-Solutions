#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#define oo 1<<30
using namespace std;
int n,m,s,t,C,caso;
vector< vector < pair <int,int> > > L;
void dijkstra(){
    vector<int> d(n,oo);
    priority_queue< pair<int,int> > Q;
    d[s]=0;
    Q.push(make_pair(d[s],s));
    while(!Q.empty()){
        int u=Q.top().second;
        int cur_d=-Q.top().first;
        Q.pop();
        if(cur_d>d[u])continue;
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i].first;
            int len=L[u][i].second;
            if(d[u]+len<d[to]){
                d[to]=d[u]+len;
                Q.push(make_pair(-d[to],to));
                }
            }
        }
    if(d[t]==oo)printf("Case #%d: unreachable\n",++caso);
    else printf("Case #%d: %d\n",++caso,d[t]);
    }
void doit(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    L.clear();
    L.resize(n,vector<pair<int,int> >());
    int x,y,w;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&x,&y,&w);
        L[x].push_back(make_pair(y,w));
        L[y].push_back(make_pair(x,w));
        }
    dijkstra();
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
