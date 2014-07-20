#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
#define N 105
char c[1000];
vector<int> L[N];
int d[N],low[N],parent[N],last[N],child[N];
bool used[N],cutP[N];
int x,y,timer,n;

void dfs(int r){
    
    stack<int> S;
    S.push(r);
    parent[r]=-1;
    used[r]=true;
    d[r]=low[r]=timer++;
    
    while(!S.empty()){
        int u=S.top();
        for(int &i=last[u];i<L[u].size();++i){
            int to=L[u][i];
            if(parent[u]==to)continue;
            if(used[to])low[u]=min(low[u],d[to]);
            else{
                S.push(to);
                used[to]=true;
                d[to]=low[to]=timer++;
                parent[to]=u;
                ++child[u];
                break;
                }
            }
        
        if(last[u]==L[u].size()){
            S.pop();
            if(u!=r){
                low[parent[u]]=min(low[parent[u]],low[u]);
                if(low[u]>=d[parent[u]] && parent[u]!=r)cutP[parent[u]]=true;
                }
            }
        }
    
    if(child[r]>1)cutP[r]=true;
    }
    
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)L[i].clear();
    gets(c);
    while(1){
        gets(c);
        if(c[0]=='0')break;
        int Ct=0,ct=0;
        sscanf(c+Ct,"%d%n",&x,&ct);
        --x;
        Ct+=ct;
        while(1){
            if(sscanf(c+Ct,"%d%n",&y,&ct)!=1)break;
            --y;
            Ct+=ct;
            L[x].push_back(y);
            L[y].push_back(x);
            }
        }
    memset(used,false,sizeof(bool)*(n+1));
    memset(cutP,false,sizeof(bool)*(n+1));
    memset(last,0,sizeof(int)*(n+1));
    memset(child,0,sizeof(int)*(n+1));
    timer=0;
    for(int i=0;i<n;++i)if(!used[i])dfs(i);
    int ans=0;
    for(int i=0;i<n;++i)ans+=cutP[i];
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
