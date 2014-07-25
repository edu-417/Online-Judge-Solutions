#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100
#define oo (1<<20)
int n,C,S,T;
int cnt[256];
int c[N+30][N+30];
char s[N+5];
vector<int> L[N+30];
bool used[N+30];
char cad[10];
int dfs(int u,int fp){
    if(used[u])return 0;
    used[u]=true;
    if(u==T)return fp;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(c[u][to]==0)continue;
        int f=dfs(to,min(c[u][to],fp));
        if(f==0)continue;
        c[u][to]-=f;
        c[to][u]+=f;
        return f;
        }
    return 0;
    }
int maxFlow(){
    int flow=0;
    while(1){
        memset(used,false,sizeof(used));
        int f=dfs(S,oo);
        if(f==0)break;
        flow+=f;
        }
    return flow;
    }
    
void doit(){
    S=n+26, T=n+27;
    
    for(int i=0;i<n+28;++i)L[i].clear();
    memset(c,0,sizeof(c));
    
    scanf("%s",s);
    for(int i=0;i<n;++i){
        int u=i+26;
        scanf("%c",cad);
        for(int j=0;cad[j];++j){
            int to=cad[j]-'a';
            L[u].push_back(to),++c[u][to],++c[to][u];
            }
        }
    
    for(n=0;s[n];++n)++cnt[s[n]];
    
    for(int i='a',j=0;i<='z';++i,++j)L[j].push_back(T),c[j][T]=c[T][j]=cnt[i];
    
    int f=maxFlow();
    if(f<n)printf("NO SOLUTION\n");
    else{
        
        }
    
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
