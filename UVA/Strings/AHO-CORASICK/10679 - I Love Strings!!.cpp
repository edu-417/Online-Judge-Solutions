#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 1000005
int next[N][52];
int end[N],L[1005],bord[N];
bool query[N];
int nodes,cnt,q,C;
char Text[100005],cad[1005];
void add(char *s){
    int u=0,n=strlen(s);
    for(int i=0;i<n;++i){
        int c=0;
        if(s[i]>='a' && s[i]<='z')c=s[i]-'a';
        else c=s[i]-'A'+26;
        int to=next[u][c];
        if(to==0)end[nodes]=false,next[u][c]=nodes++;
        u=next[u][c];
        }
    end[u]=true;
    L[cnt++]=u;
    }
void aho_corasick(){
    queue<int> Q;
    for(int i=0;i<52;++i){
        int to=next[0][i];
        if(to)bord[to]=0, Q.push(to);
        }
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=0;i<52;++i){
            int to= next[u][i],x=next[bord[u]][i];
            if(to==0)next[u][i]=x;
            else{
                bord[to]=x;
                end[to]|=end[x];
                Q.push(to);
                }
            }
        }
    }
    
void find(char *s){
    int u=0,n=strlen(s);
    for(int i=0;i<n;++i){
        int c=0;
        if(s[i]>='a' && s[i]<='z')c=s[i]-'a';
        else c=s[i]-'A'+26;
        int to=next[u][c];
        if(end[to])query[to]=true;
        u=to;
        }
    }
void doit(){
    scanf("%s",Text);
    scanf("%d",&q);
    nodes=1;
    memset(next,0,sizeof(next));
    cnt=0;
    for(int i=0;i<q;++i)scanf("%s",cad),add(cad);
    aho_corasick();
    find(Text);
    for(int i=0;i<q;++i)printf("%s\n",query[L[i]]?"y":"n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
