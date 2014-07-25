#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
vector< vector<int> > L;
vector<bool> used;
vector<int> parent;
map<int,int> M;
int x,y,caso=0,n;
bool val;
vector<int> q;

void dfs(int u){
	used[u]= true;
	for(int i=0;i< L[u].size();++i){
		int to = L[u][i];
		if(used[to]){
            if(to!=parent[u])val=false;
            continue;
            }
		else{
            parent[to]=u;
            dfs(to);
            }
		}
	}
	
bool doit(){
	scanf("%d%d",&x,&y);
	if(x==-1 && y==-1)return false;
    n=0;
	M.clear();
	L.clear();
	while(1){
		if(x==0 && y==0)break;
		if(M.find(x)==M.end())M[x]=n++,L.push_back(q);
		if(M.find(y)== M.end())M[y]=n++,L.push_back(q);
		L[M[x]].push_back(M[y]);
 		L[M[y]].push_back(M[x]);
		scanf("%d%d",&x,&y);
		}
    printf("%d\n",n);
	used.clear();
	used.resize(n,false);
	val=true;
    parent.clear();
    parent.resize(n,-1);
	dfs(0);
	for(int i=0;i<n;++i)if(!used[i])val=false;
	if(val)printf("Case %d is a tree.\n",++caso);
	else printf("Case %d is not a tree.\n",++caso);
	return true;
	}
	
int main(){
	while(1)if(!doit())break;
	}
