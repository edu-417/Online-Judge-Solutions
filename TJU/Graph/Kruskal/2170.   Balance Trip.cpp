#include<cstdio>
#include<algorithm>
using namespace std;
#define M 1000
#define N 200
#define oo (1<<20)
struct edge{
	int u,to,w;
	edge(){}
	edge(int _u,int _to,int _w){
		u=_u;to=_to;w=_w;
		}
	};

bool operator <(const edge &e1,const edge &e2){
	return e1.w<e2.w;
	}
edge e[M+5];
int p[N+5];

int n,m,x,y,w,s,t;


int Find(int x){
	if(p[x]==x)return x;
	return p[x]=Find(p[x]);
	}
	
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	p[x]=y;
	}

bool doit(){
	scanf("%d%d",&n,&m);
	if(n==0 && m==0)return false;
	for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&w),e[i]=edge(--x,--y,w);
	scanf("%d%d",&s,&t);--s;--t;
	sort(e,e+m);
	int ans=oo;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)p[j]=j;
		int shortest=e[i].w;
		int longest=-1;
		for(int j=i;j<m;++j){
			if( Find(e[j].u)!=Find(e[j].to) ){
					Union(e[j].u,e[j].to);
					if(Find(s)==Find(t)){
					longest=e[j].w;
					break;
					}
				}
			}
		if(longest==-1)continue;
		ans=min(ans,longest-shortest);
		}
	printf("%d\n",ans==oo?-1:ans);
		
	return true;
	}
int main(){
	while(1)if(!doit())break;
	}
