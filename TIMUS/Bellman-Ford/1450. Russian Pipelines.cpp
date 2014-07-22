#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100000
vector< pair < int, pair<int,int> > > edge;

int n,m,s,t,x,y,w;
int d[N+5];
inline int getU(const int idx){
    return edge[idx].second.first;
    }
    
inline int getTo(const int idx){
    return edge[idx].second.second;
    }

inline int getW(const int idx){
    return edge[idx].first;
    }
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&w),edge.push_back(make_pair(w,make_pair(--x,--y)));
    scanf("%d%d",&s,&t);
    memset(d,-1,sizeof(int)*n);
    d[--s]=0;
    for(;;){
        bool ok=true;
        for(int j=0;j<m;++j)
            if(d[getU(j)]>-1)
                if(d[getTo(j)]<d[getU(j)]+getW(j))ok=false,d[getTo(j)]=d[getU(j)]+getW(j);
        if(ok)break;
        }
    if(d[--t]<0)printf("No solution\n");
    else printf("%d\n",d[t]);
    }
