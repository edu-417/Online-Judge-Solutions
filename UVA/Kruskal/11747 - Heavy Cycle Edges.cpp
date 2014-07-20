#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    int x,y,c;
    edge(){}
    edge(int _x,int _y,int _c){
        x=_x;
        y=_y;
        c=_c;
        }
    };
bool operator < (edge e1,edge e2){
    return e1.c<e2.c;
    }
#define N 1000
#define M 25000
edge E[M+5];
int n,m,C,caso=0;
int parent[N+5];
int Find(int u){
    if(parent[u]==u)return u;
    return parent[u]=Find(parent[u]);
    }
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    parent[y]=x;
    }
bool doit(){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)return false;
    for(int i=0;i<n;++i)parent[i]=i;
    int x,y,z;
    for(int i=0;i<m;++i)scanf("%d%d%d",&x,&y,&z),E[i]=edge(x,y,z);
    sort(E,E+m);
    vector<int> ans;
    for(int i=0;i<m;++i){
        if(Find(E[i].x)!=Find(E[i].y))Union(E[i].x,E[i].y);
        else ans.push_back(E[i].c);
        }
    if(ans.size()==0)printf("forest");
    else
        for(int i=0;i<ans.size();++i)printf("%s%d",i==0?"":" ",ans[i]);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
