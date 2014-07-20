#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
bool b[256],Q[256];
vector<int> order;
vector< vector<int> > v;
vector<int> L[256];
int in[256];
char c[1000];
int x,y,caso=0;
void back(){
    bool empty=true;
    for(int u='a';u<='z';++u){
        if(!b[u])continue;
        if(!Q[u])continue;
        empty=false;
        Q[u]=false;
        order.push_back(u);
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            --in[to];
            if(in[to]>0)continue;
            Q[to]=true;
            }
        back();
        Q[u]=true;
        for(int i=0;i<L[u].size();++i){
            int to=L[u][i];
            ++in[to];
            if(in[to]==1)Q[to]=false;
            }
        order.pop_back();
        }
    if(empty){
        v.push_back(order);
        }
    }
bool doit(){
    if(!gets(c))return false;
    
    for(int i=0;i<256;++i)L[i].clear();
    memset(in,0,sizeof(in));
    memset(Q,false,sizeof(Q));
    memset(b,false,sizeof(b));
    string s(c);
    for(int i=0;i<s.length();++i)
        if(s[i]==' ')continue;
        else b[s[i]]=true;
    gets(c);
    s=string(c);
    bool primero=true;
    for(int i=0;i<strlen(c);++i)
        if(s[i]==' ')continue;
        else if(primero)x=s[i],primero^=1;
        else y=s[i],L[x].push_back(y),primero^=1,++in[y];
    for(int i='a';i<='z';++i)if(b[i] && in[i]==0)Q[i]=true;
    v.clear();
    back();
    if(caso++>0)printf("\n");
    for(int i=0;i<v.size();++i){
        for(int j=0;j<v[i].size();++j)putchar(char(v[i][j]));
        printf("\n");
        }
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
