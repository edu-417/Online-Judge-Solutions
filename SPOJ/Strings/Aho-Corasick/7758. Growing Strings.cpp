#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 10000
#define L 1000
#define NODES 1000000
#define ALPH 26
char s[L+5];
int dp[NODES+5],border[NODES+5],parent[NODES+5];
bool end[NODES+5];
int trie[NODES+5][ALPH];
int nodes,n;
void add(char *s){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]-'a']==0)trie[u][s[i]-'a']=nodes++;
        u=trie[u][s[i]-'a'];
        }
    end[u]=true;
    }

void aho(){
    queue<int> Q;
    for(int i=0;i<ALPH;++i){
        int u=trie[0][i];
        if(u>0)Q.push(u),parent[u]=0;
        }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<ALPH;++i){
            int to=trie[u][i];
            int b=trie[border[u]][i];
            if(to==0)trie[u][i]=b;
            else Q.push(to),border[to]=b,parent[to]=u;
            }
        }
    }
void init(){
    for(int i=0;i<nodes;++i)memset(trie[i],0,sizeof(int)*ALPH);
    memset(border,0,sizeof(int)*nodes);
    memset(end,false,sizeof(bool)*nodes);
    nodes=1;
    }
int f(int u){
    if(u==0)return 0;
    int &ret=dp[u];
    if(ret>-1)return ret;
    int ans=max(f(border[u]),f(parent[u]))+end[u];
    return ret=ans;
    }

bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    init();
    for(int i=0;i<n;++i)scanf("%s",s),add(s);    
    aho();
    int ans=0;
    memset(dp,-1,sizeof(int)*nodes);
    for(int i=1;i<nodes;++i)if(end[i])ans=max(ans,f(i));
    printf("%d\n",ans);
    return true;
    }
int main(){
    int nodes=0;
    while(1)if(!doit())break;
    return 0;
    }
