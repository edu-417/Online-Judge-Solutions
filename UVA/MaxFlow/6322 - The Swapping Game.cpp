#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100
int n,C;
int cnt[256];
int c[N+30][N+30];
char s[N+5];
vector<int> L[N+5];
void doit(){
    int S=n+26, T=n+27;
    
    for(int i=0;i<n+28;++i)L[i].clear();
    memset(c,0,sizeof(c));
    
    scanf("%s",s);
    
    for(n=0;s[n];++n)++cnt[s[n]];
    
    for(int i='a',j=0;i<='z';++i,++j)L[S].push_back(j);
    printf("%d\n",'z'-'a');
    
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
