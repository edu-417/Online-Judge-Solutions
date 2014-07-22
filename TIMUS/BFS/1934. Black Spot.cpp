#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define N 100000
vector< vector<int> > L,p;
int s,t,n,m,x,y,z;
float dp[N+5];
int d[2][N+5];
int next[N+5];
void bfs(int idx){
	vector<bool> used(n,false);
	queue<int> Q;
	if(idx==0)Q.push(s),d[idx][s]=0,used[s]=true;
	else Q.push(t),	d[idx][t]=0,used[t]=true;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<L[u].size();++i){
			int to=L[u][i];
			if(used[to])continue;
			used[to]=true;
			d[idx][to]=d[idx][u]+1;
			Q.push(to);
		}
	}
}

double dfs(int u,int parent=-1){
	if(u==t)return 1.0;
	float &ret=dp[u];
	if(ret>-0.5)return ret;
	double ans=0;
	for(int i=0;i<L[u].size();++i){
		int to=L[u][i];
		if(to==parent)continue;
		if(d[1][to]+d[0][to]==d[0][t]){
			double aux=(1.0-p[u][i]/100.0)*dfs(to,u);
			if(ans<aux)ans=aux,next[u]=to;
		}
	}
	return ret=ans;
}

void rec(){
	for(int u=s;u!=t;u=next[u])printf("%d ",u+1);
	printf("%d\n",t+1);
	}
bool doit(){
	if(scanf("%d%d",&n,&m)!=2)return false;
	L.clear();p.clear();L.resize(n);p.resize(n);
	scanf("%d%d",&s,&t);
	--s,--t;
	for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&z),L[--x].push_back(--y),L[y].push_back(x),p[x].push_back(z),p[y].push_back(z);
	bfs(0);
	bfs(1);
	for(int i=0;i<n;++i)dp[i]=-1.0;
	double ans=1.0-dfs(s);
	printf("%d %lf\n",d[0][t]+1,ans);
	rec();
	return true;
}

int main(){
	while(1)if(!doit())break;
}
