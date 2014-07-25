#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int x,y;
#define N 1000
#define oo 1<<30
vector<int> L[N+5];
pair<int,int> Q[N+5];
int C,n,m,k;
bool used[N+5],used2[N+5];
int in[N+5],cont[N+5],c[N+5];
bool dfs(int u){
    if(used[u])return false;
    if(used2[u])return false;
    used2[u]=true;
    c[u]=C;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    return true;
    }
bool doit(){
	scanf("%d",&n);
	if(n==0)return false;
	scanf("%d%d",&m,&k);
	for(int i=0;i<n;++i)L[i].clear();
	memset(in,0,sizeof(int)*n);
	for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x),++in[y],++in[x];
    memset(used,false,sizeof(bool)*n);
    while(1){
        for(int i=0;i<n;++i)
            if(used[i])Q[i]=make_pair(oo,i);
            else Q[i]=make_pair(in[i],i);
        sort(Q,Q+n);
        pair<int,int> top=Q[0];
        if(top.first>=k)break;
        for(int i=0;i<L[top.second].size();++i){
            int to=L[top.second][i];
            in[to]--;
            }
        used[top.second]=true;
        }
    memset(used2,false,sizeof(bool)*n);
	C=0;
	for(int i=0;i<n;++i)C+=dfs(i);
    int ans=0;
    memset(cont,0,sizeof(int)*C);
	for(int i=0;i<n;++i)if(!used[i])cont[c[i]]++;
    for(int i=0;i<C;++i)ans=max(ans,cont[i]);
    cout<<ans<<endl;
	return true;
	}
int main(){
	while(1)if(!doit())break;
	}
