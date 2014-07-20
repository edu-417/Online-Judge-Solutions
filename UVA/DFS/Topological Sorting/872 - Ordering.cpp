#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool b[256],Q[256];
vector<int> order;
vector< vector<int> > v;
vector<int> L[256];
bool cycle;
int in[256];
char s[1000],c[10];
int x,y,caso=0,C;
void back(){
    if(cycle)return;
    bool empty=true;
    for(int u='A';u<='Z';++u){
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
        for(int u='A';u<='Z';++u)if(!b[u])continue;
        else if(in[u]>0)cycle=true;
        v.push_back(order);
        }
    }
void doit(){
    gets(s);
    gets(s);
    for(int i=0;i<256;++i)L[i].clear();
    memset(in,0,sizeof(in));
    memset(Q,false,sizeof(Q));
    memset(b,false,sizeof(b));
    for(int i=0;s[i];++i)
        if(s[i]==' ')continue;
        else b[s[i]]=true;
    gets(s);
    int Ct=0,ct=0;
    while(1){
        if(sscanf(s+Ct,"%s%n",c,&ct)!=1)break;
        Ct+=ct;
        L[c[0]].push_back(c[2]);
        ++in[c[2]];
        }
    for(int i='A';i<='Z';++i)if(b[i] && in[i]==0)Q[i]=true;
    v.clear();
    cycle=false;
    back();
    if(caso++>0)printf("\n");
    if(cycle)printf("NO\n");
    else{
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[i].size();++j){if(j>0)putchar(' ');putchar(char(v[i][j]));}
            printf("\n");
            }
        }
    }

int main(){
    scanf("%d",&C);
    gets(s);
    for(int i=0;i<C;++i)doit();
    }
