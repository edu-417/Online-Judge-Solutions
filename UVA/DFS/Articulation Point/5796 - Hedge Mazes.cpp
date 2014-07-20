#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char cad[10000005],cad2[10],cad3[10];

vector<int> adj[10005];
int padre[10005];
int parent[10005];
int rank[10005];
int hijos[10005];
int d[10005];
int low[10005];
int n,m,q;
void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
    }

void Link(int x,int y){
    if(rank[x]>rank[y])parent[y]=x;
    else parent[x]=y;
        if(rank[x]==rank[y])rank[y]++;
    }

int Find_Set(int x){
    if(x!=parent[x])parent[x]=Find_Set(parent[x]);
    return parent[x];
    }

void Union(int x,int y){
    Link(Find_Set(x),Find_Set(y));
    }
void edge(int x, int y){
   adj[x].push_back(y);
   adj[y].push_back(x);
   }
void dfs(int u,int nivel){
   low[u]=nivel;
   d[u]=nivel;
   hijos[u]=0;
   bool vuelta=true;
   for(int i=0;i<adj[u].size();i++){
      int v=adj[u][i];
      if(v==padre[u]){
         if(vuelta)vuelta=false;
         else low[u]=min(low[u],d[v]);
         }
      else if(d[v]!=-1)low[u]=min(low[u],d[v]);
         else{
            padre[v]=u;
            hijos[u]++;
            dfs(v,nivel+1);
            low[u]=min(low[u],low[v]);
            }
      }
   }

bool doit(){
   scanf("%d%d%d",&n,&m,&q);
   if(n==0 && m==0 && n==0)return false;
   for(int i=0;i<=n;i++)adj[i].clear();
   int x,y;
   for(int i=0;i<m;i++)scanf("%d%d",&x,&y),edge(x,y);
   memset(padre,-1,sizeof(int)*(n+2));
   memset(d,-1,sizeof(int)*(n+2));
   memset(hijos,0,sizeof(int)*(n+2));
   for(int i=1;i<=n;i++)if(d[i]==-1)dfs(i,0);
   for(int i=0;i<=n;i++)Make_Set(i);
   for(int u=1;u<=n;u++)if(padre[u]!=-1)if(low[u]>d[padre[u]])Union(u,padre[u]);
   for(int i=0;i<q;i++){
      scanf("%d%d",&x,&y);
      printf("%s\n",Find_Set(x)==Find_Set(y)? "Y":"N");
      }
   printf("-\n");
   return true;
   }
int main(){
   while(1)if(!doit())break;
   }
