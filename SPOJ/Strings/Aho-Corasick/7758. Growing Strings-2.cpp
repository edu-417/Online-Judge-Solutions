#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10000
#define L 1000
#define NODES 1000000
char s[L+5];
int dp[NODES+5],border[NODES+5],parent[NODES+5];
bool end[NODES+5];
vector< pair<char,int> > trie[NODES+5];
int nodes,n;

inline int getNode(int u,char c){
    for(int i=(int)trie[u].size()-1;i>=0;--i)if(trie[u][i].first==c)return trie[u][i].second;
    return 0;
    }

void add(char *s){
    int u=0;
    for(int i=0;s[i];++i){
        int to=getNode(u,s[i]);
        if(to==0)trie[u].push_back(make_pair(s[i],nodes)),u=nodes++;
        else u=to;
        }
    end[u]=true;
    }

void aho(){
    queue<int> Q;
    for(int i=(int)trie[0].size()-1;i>=0;--i){
        int u=trie[0][i].second;
        Q.push(u),parent[u]=0;
        }        
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=(int)trie[u].size()-1;i>=0;--i){
            int to=trie[u][i].second;
            int c=trie[u][i].first;
            int b=border[u];
            while(b>0 && getNode(b,c)==0)b=border[b];
            b=getNode(b,c);
            Q.push(to),border[to]=b,parent[to]=u;
            }
        }
    }
void init(){
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
    for(int i=0;i<nodes;++i)trie[i].clear();
    printf("%d\n",ans);
    return true;
    }
int main(){
    nodes=1;
    while(1)if(!doit())break;
    return 0;
    }
