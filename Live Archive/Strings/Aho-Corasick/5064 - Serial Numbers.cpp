#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
#define NODES 100
#define ALPH 256
char op[15];
int trie[NODES+5][ALPH];
int border[NODES+5];
bool end[NODES+5];
long long dp[35][35][NODES+5];
int nodes,k,q,n,C;
void init(){
    memset(trie,0,sizeof(trie));
    memset(border,0,sizeof(border));
    memset(end,false,sizeof(end));
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
    for(int i='0';i<='9';++i){
        int u=trie[0][i];
        if(u>0)border[u]=0,Q.push(u);
        }
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i='0';i<='9';++i){
            int to=trie[u][i];
            int b=trie[border[u]][i];
            if(to==0)trie[u][i]=b;
            else Q.push(to),end[to]|=end[b],border[to]=b;
            }
        }
    }

long long f(int L,int pos,int u){
    if(end[u])return 0;
    if(pos==L)return 1;
    long long &ret=dp[L][pos][u];
    if(ret>-1)return ret;
    long long ans=0;
    int start='0';
    if(pos==0)start='1';
    for(int i=start;i<='9';++i)ans+=f(L,pos+1,trie[u][i]);
    return ret=ans;
    }

long long count(int n){
    return f(n,0,0);
    }

string Serial(int n,int L){
    int u=0;
    string ans="";
    for(int i=0;i<L;++i){
        int start='0';
        if(i==0)start='1';
        for(int j=start;j<='9';++j){
            long long aux=f(L,i+1,trie[u][j]);
            if(n>aux)n-=aux;
            else{
                ans+=char(j);
                u=trie[u][j];
                break;
                }
            }
        }
    return ans;
    }
    
string getSerial(int n){
    if(n==0)return "0";
    for(int i=1;i<40;++i){
        long long aux=count(i);
        if(n>aux)n-=aux;
        else return Serial(n,i);
        }
    }
void doit(){
    init();
    scanf("%d",&k);
    for(int i=0;i<k;++i)scanf("%s",op),add(op);
    aho();
    memset(dp,-1,sizeof(dp));
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d",&n);
        printf("%s%s",i==0?"":" ",getSerial(n).c_str());
        }
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
