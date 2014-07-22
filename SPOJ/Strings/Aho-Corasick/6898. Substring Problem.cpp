#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define M 100000
#define N 1000
#define L 2000
#define ALPH 256
#define NODES N*L
int trie[NODES+5][ALPH];
bool query[N+5];//end[NODES+5];
int border[N+5];
int nodes,n;
char s[L+5];
char S[M+5];
vector<int> ind[NODES+5];
void add(char *s,const int idx){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]]==0)trie[u][s[i]]=nodes++;
        u=trie[u][s[i]];
        }
    //end[u]=true;
    ind[u].push_back(idx);
    }
    
void aho(){
    queue<int> Q;
    char * start="aA0";
    char * end="zZ9";
    for(int i=0;i<3;++i)
        for(int j=start[i];j<=end[i];++j)if(trie[0][i]>0)Q.push(trie[0][i]);
    
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<3;++i)
            for(int j=start[i];j<=end[i];++j){
                int to=trie[u][i];
                int b=trie[border[u]][i];
                if(to==0)trie[u][i]=b;
                else{
                    Q.push(trie[u][i]),border[to]=b;//end[to]|=end[b];
                    for(int j=(int)ind[b].size()-1;j>=0;--j)ind[to].push_back(ind[b][j]);
                    }
                }
        }
    }

void init(){
    //memset(end,false,sizeof(bool)*nodes);
    memset(border,0,sizeof(int)*nodes);
    for(int i=0;i<nodes;++i)memset(trie[i],0,sizeof(int)*ALPH);
    for(int i=0;i<nodes;++i)ind[i].clear();
    }
int main(){
    scanf("%s",S);
    scanf("%d",&n);
    init();
    for(int i=0;i<n;++i)scanf("%s",s),add(s,i);
    aho();
    int u=0;
    for(int i=0;S[i];++i){
        int to=trie[u][S[i]];
        for(int j=ind[to].size()-1;j>=0;--j)query[ind[to][j]]=true;
        u=to;
        }
    for(int i=0;i<n;++i)scanf("%s\n",query[i]?"Y":"N");
    }
