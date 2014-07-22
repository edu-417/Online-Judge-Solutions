#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 50
#define oo (1<<30)
int a[N+5][N+5];
int mt[N+5];
int idx[N+5];
bool used[N+5],used1[N+5];
int n,C;
vector< pair<int,int> > edges[N+5];
vector<pair<int,int> > L[N+5];

inline bool dfs(int u){
    if(used[u])return false;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i].second;
        if(mt[to]==-1 || dfs(mt[to])){
            mt[to]=u;
            return true;
            }
        }
    return false;
    }
void init(){
    memset(mt,-1,sizeof(int)*n);
    memset(used1,false,sizeof(bool)*n);
    memset(idx,0,sizeof(int)*n);
    }

inline bool p(){
    for(int i=0;i<n;++i){
        if(used1[i])continue;
        memset(used,false,sizeof(bool)*n);
        dfs(i);
        }
    int ans=0;
    for(int i=0;i<n;++i)if(mt[i]!=-1)used1[mt[i]]=true,++ans;
    if(ans==n)return true;
    return false;
    }

inline void fixGraph(const int &menor ){
    for(int i=0;i<n;++i)if(mt[i]!=-1)
        if(a[mt[i]][i]<menor)used1[mt[i]]=false,mt[i]=-1;        
    for(int i=0;i<n;++i)
        while(L[i].size()>0 && L[i][0].first<menor)L[i].erase(L[i].begin());
    }

inline void updateGraph(const int & mayor){
    for(int i=0;i<n;++i)
        for(; idx[i]<edges[i].size() && edges[i][ idx[i] ].first<=mayor; ++idx[i]) L[i].push_back(edges[i][idx[i]]);
    }
    
int f(){
    int ans=oo;
    vector<int> v;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)v.push_back(a[i][j]);
    sort(v.begin(),v.end());
    int L=v.size();
    init();
    for(int i=0,j=0;i<L;++i){
        if(i>j)i=j;
        fixGraph(v[i]);
        for(;j<L;++j){
            updateGraph(v[j]);
            if(p()){
                ans=min(ans,v[j]-v[i]);
                break;
                }
            }
        if(j==L)break;
        }
    return ans;
    }
    
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",a[i]+j);
    for(int i=0;i<n;++i)edges[i].clear();
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)edges[i].push_back( make_pair(a[i][j],j) );
    for(int i=0;i<n;++i)sort(edges[i].begin(),edges[i].end());
    int ans=f();
    printf("%d\n",ans);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }

