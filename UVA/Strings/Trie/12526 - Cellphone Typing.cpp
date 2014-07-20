#include<cstdio>
#include<cstring>
#define N 100000
#define L 80
#define MAXL 10
#define alphabet 26
char s[N+5][L+5];
int trie[MAXL+5][alphabet+5];
int nodes,n;
int cnt[MAXL+5];
bool end[MAXL+5];
void init_trie(){
    nodes=1;
    memset(trie,-1,sizeof(trie));
    }
void add(char *s){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][ s[i]-'a' ]==-1)trie[u][ s[i]-'a' ]=nodes++,++cnt[u];
        u=trie[u][s[i]-'a'];
        }
    end[u]=true;
    }
int keystrokes(char *s){
    int u=0;
    int ans=0;
    for(int i=0;s[i];++i){
        u=trie[u][s[i]-'a'];
        if(end[u] || cnt[u]>1)++ans;
        }
    return ans;
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    memset(cnt,0,sizeof(cnt));
    memset(end,false,sizeof(end));
    init_trie();
    for(int i=0;i<n;++i)scanf("%s",s[i]),add(s[i]);
    int ans=0;
    for(int i=0;i<n;++i)ans+=keystrokes(s[i]);
    printf("%.2lf\n",ans*1.0/n);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
