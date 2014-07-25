#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define NODES 240
#define ALPH 256
bool end[NODES+5];
int border[NODES+5];
int trie[NODES+5][ALPH];

char s[30];
int nodes,n,m;
void init(){
    memset(end,false,sizeof(end));
    memset(border,0,sizeof(border));
    memset(trie,0,sizeof(trie));
    nodes=1;
    }
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
    for(int i='a';i<='z';++i){
        int u=trie[0][i];
        if(u>0)border[u]=0,Q.push(u);
        }
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i='a';i<='z';++i){
            int to=trie[u][i];
            int b=trie[border[u]][i];
            if(to==0)trie[u][i]=b;
            else Q.push(to),border[to]=b,end[to]|=end[b];
            }
        }    
    }

bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    init();
    for(int i=0;i<n;++i)scanf("%s",s),add(s);
    aho();
    for(int i=0;i<)
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
