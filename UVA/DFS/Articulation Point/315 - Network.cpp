#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
char c[1000];
#define N 105
vector<int> L[N];
int d[N],low[N];
bool used[N],cutP[N];
int x,y,timer,n;
void dfs(int u,int p=-1){
    used[u]=true;
    low[u]=d[u]=timer++;
    int child=0;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(to==p)continue;
        if(used[to])
            low[u]=min(low[u],d[to]);
        else{
            dfs(to,u);
            low[u]=min(low[u],low[to]);
            ++child;
            if(low[to]>=d[u] && p!=-1)cutP[u]=true;
            }
        }
    if(p==-1 && child>1)cutP[u]=true;
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
