#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 50
#define L 1000
#define ALPH 256
#define oo 1<<30
char s[L+5];
char DNA[] ="ACGT";
int trie[L+5][ALPH],dp[L+5][L+5];
int border[L+5];
int nodes,n,m,caso;
bool end[L+5];
void add(char *s){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]]==0)trie[u][s[i]]=nodes++;
        u=trie[u][s[i]];
        }
    end[u]=true;
    }

void aho(){
    queue<int> Q;
    for(int i=0;i<4;++i){
        int u=trie[0][DNA[i]];
        if(u>0)Q.push(u);
        }
    
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<4;++i){
            int to=trie[u][DNA[i]];
            int b=trie[border[u]][DNA[i]];
            if(to==0)trie[u][DNA[i]]=b;
            else Q.push(to),border[to]=b,end[to]|=end[b];
            }
        }
    }

void init(){
    for(int i=0;i<nodes;++i)memset(trie[i],0,sizeof(int)*ALPH);
    memset(border,0,sizeof(int)*nodes);
    memset(end,false,sizeof(bool)*nodes);
    nodes=1;
    }
int f(int pos,int u){
    if(end[u])return oo;
    if(pos==m)return 0;
    int &ret=dp[pos][u];
    if(ret>-1)return ret;
    int ans=oo;
    for(int i=0;i<4;++i)ans=min( ans, f( pos+1, trie[u][DNA[i]] ) + (int)(DNA[i]!=s[pos]) );
    return ret=ans;
    }
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    init();
    for(int i=0;i<n;++i)scanf("%s",s),add(s);
    aho();
    scanf("%s",s);
    m=strlen(s);
    for(int i=0;i<m;++i)memset(dp[i],-1,sizeof(int)*nodes);
    int ans=f(0,0);
    printf("Case %d: %d\n",++caso,ans==oo?-1:ans);
    return true;
    }
int main(){
    nodes=1;
    caso=0;
    while(1)if(!doit())break;
    }
