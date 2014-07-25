#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define N 10
#define L 100
#define NODES N*L
#define ALPH 256

char * DNA="ACGT";
int trie[NODES+5][ALPH];
int ind[NODES+5],border[NODES+5];
int w[N+5];
int n,m,nodes;
char s[L+5];
int dp[2][NODES+5][(1<<N)];
void add(char *s,const int idx){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]]==0)trie[u][s[i]]=nodes++;
        u=trie[u][s[i]];
        }
    ind[u]|=(1<<idx);
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
            else Q.push(to),border[to]=b,ind[to]|=ind[b];
            }
        }
    }

void init(){
    memset(border,0,sizeof(int)*nodes);
    memset(ind,0,sizeof(int)*nodes);
    for(int i=0;i<nodes;++i)
        for(int j=0;j<4;++j)trie[i][DNA[j]]=0;
    nodes=1;
    }

int f(){
    
    for(int j=0;j<nodes;++j)
        for(int k=0;k<(1<<n);++k){
            int sum=0;
            for(int i=0;i<n;++i)if((k>>i)&1)sum+=w[i];
            dp[m&1][j][k]=sum;
            }
    for(int i=m-1;i>=0;--i)
        for(int j=0;j<nodes;++j)
            for(int k=0;k<(1<<n);++k){
                int ans=-(1<<30);
                for(int q=0;q<4;++q){
                    int to=trie[j][DNA[q]];
                    ans=max(ans,dp[(i+1)&1][to][k|ind[to]]);
                    }
                dp[i&1][j][k]=ans;
                }
    }
    
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    init();
    for(int i=0;i<n;++i){
        scanf("%s%d",s,w+i);
        add(s,i);
        }
    aho();    
    f();
    int ans=dp[0][0][0];
    if(ans<0)printf("No Rabbit after 2012!\n");
    else printf("%d\n",ans);
    return true;
    }
    
int main(){
    nodes=1;
    while(1)if(!doit())break;
    }
