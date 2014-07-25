#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define N 20000
vector<int> L[N+5],LT[N+5];
vector<int> order;
int n,m,scc,x,y;
int c[N+5];
bool used[N+5];
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    }
bool dfs_scc(int u){
    if(used[u])return false;
    used[u]=true;
    c[u]=scc;
    for(int i=0;i<LT[u].size();++i){
        int to=LT[u][i];
        dfs_scc(to);
        }
    return true;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<(m<<1);++i)L[i].clear(),LT[i].clear();
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        if(x==0 && y==0);
        else{
            if(x==0)x=y;
            else if(y==0)y=x;
            --x,--y;
            L[(x<<1)+1].push_back(y<<1);
            L[(y<<1)+1].push_back(x<<1);
            LT[x<<1].push_back((y<<1)+1);
            LT[y<<1].push_back((x<<1)+1);
            }
        scanf("%d%d",&x,&y);
        if(x==0 && y==0);
        else{
            if(x==0)x=y;
            else if(y==0)y=x;
            --x,--y;
            L[x<<1].push_back((y<<1)+1);
            L[y<<1].push_back((x<<1)+1);
            LT[(x<<1)+1].push_back(y<<1);
            LT[(y<<1)+1].push_back(x<<1);
            }
        }
    order.clear();
    memset(used,false,sizeof(bool)*(m<<1));
    for(int i=0;i<(m<<1);++i)dfs(i);
    scc=0;
    memset(used,false,sizeof(bool)*(m<<1));
    for(int i=(m<<1)-1;i>=0;--i)scc+=dfs_scc(order[i]);
    bool ans=true;
    for(int i=0;i<(m<<1);++i)
        if(c[i]==c[i^1])ans=false;
    if(ans)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return true;
    }
int main(){
    ios::sync_with_stdio(false);
    while(1)if(!doit())break;
    }
