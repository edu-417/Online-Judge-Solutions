#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define M 100000
#define N 1000
#define L 2000
#define ALPH 256
#define NODES N*L
int trie[M+5][ALPH];
bool query[N+5];
int border[M+5];
int nodes,n;
char s[L+5], S[M+5];

vector<int> ind[M+5];

inline void add(char *s,const int & idx){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]]==0)trie[u][s[i]]=nodes++;
        u=trie[u][s[i]];
        }
    ind[u].push_back(idx);
    }
    
void aho(){
    queue<int> Q;
    for(int i=0;i<256;++i)if(trie[0][i]>0)Q.push(trie[0][i]);
    
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<256;++i){
            int to=trie[u][i];
            int b=trie[border[u]][i];
            if(to==0)trie[u][i]=b;
            else{
                Q.push(to),border[to]=b;
                for(int j=(int)ind[b].size()-1;j>=0;--j)ind[to].push_back(ind[b][j]);
                }
            }
        }
    }

void init(){
    nodes=1;
    }
int main(){
    scanf("%s",S);
    scanf("%d",&n);
    init();
    for(int i=0;i<n;++i)scanf("%s",s),add(s,i);
    aho();
    int u=0;
    for(int i=0;S[i];++i){
        u=trie[u][S[i]];
        for(int j=(int)ind[u].size()-1;j>=0;--j)query[ind[u][j]]=true;
        }
    for(int i=0;i<n;++i)printf("%s\n",query[i]?"Y":"N");
    }
