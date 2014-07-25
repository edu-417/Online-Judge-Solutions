#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define N 200
#define oo (1<<29)
char s[N+5][100000];
bool used[N+5];
bool root[N+5];
int dpI[N+5][N+5];
int dp[N+5][N+5];
int value[N+5];
map<string,int> M;

vector<int> L[N+5];
int n,m;
int dfs(int u){
    if(used[u])return 0;
    used[u]=true;
    
    int ans=0;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        ans+=1+dfs(to);
        }

    int children=L[u].size();
    for(int i=0;i<=children;++i)
        for(int j=0;j<=m;++j)dpI[i][j]=oo;
    dpI[children][0]=0;
    
    for(int i=children-1;i>=0;--i)
        for(int j=0;j<=m;++j){
            int aux=oo;
            for(int k=0;k<=j;++k)aux=min( aux , dpI[i+1][j-k] + dp[ L[u][i] ][k] );
            dpI[i][j]=aux;
            }
    
    for(int i=0;i<=m;++i){
        if(u==0)dp[u][i]=dpI[0][i];
        else if(i<=ans+1)dp[u][i]=min(value[u],dpI[0][i]);
        else dp[u][i]=oo;
        }
        
    return ans;    
    }

char c[105];
bool doit(){
    gets(c);
    if(c[0]=='#')return false;
    sscanf(c,"%d%d",&n,&m);
    for(int i=0;i<=n;++i)L[i].clear();
    memset(root,true,sizeof(bool)*(n+1));
    for(int i=0;i<n;++i){
        gets(s[i]);
        sscanf(s[i],"%s",c);
        M[string(c)]=i+1;
        }
    
    for(int i=0;i<n;++i){
        int Ct=0,ct=0;
        sscanf(s[i],"%s%d%n",c,value+(i+1),&ct);
        Ct+=ct;
        while( sscanf(s[i]+Ct,"%s%n",c,&ct)==1){
            Ct+=ct;
            L[i+1].push_back( M[string(c)] );
            root[M[string(c)]]=false;
            }
        }
    
    for(int i=1;i<=n;++i)if(root[i])L[0].push_back(i);   
    memset(used,false,sizeof(bool)*(n+1));
    dfs(0);
    int ans=dp[0][m];
    printf("%d\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
