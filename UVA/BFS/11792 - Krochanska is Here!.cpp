#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 10005
vector<int> v,principal,L[N];
int n,s,x,C;
bool b[N],p[N];
vector<int> d;
void bfs(int source){
    queue<int> Q;
    d.clear();
    d.resize(n,-1);
    Q.push(source);
    d[source]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(size_t i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(d[to]!=-1)continue;
            d[to]=d[u]+1;
            Q.push(to);
            }
        }
    }
void doit(){
    scanf("%d%d",&n,&s);
    printf("%d %d\n",n,s);
    memset(b,false,sizeof(bool)*n);
    memset(p,false,sizeof(bool)*n);
    for(int i=0;i<n;++i)L[i].clear();
    principal.clear();
    for(int i=0;i<s;++i){
        v.clear();
        for(int j=0;;++j){
            scanf("%d",&x);
            printf("%d ",x-1);
            if(x==0)break;
            v.push_back(--x);
            if(b[x] && !p[x])principal.push_back(x),p[x]=true;
            b[x]=true;
            }
        printf("\n");
        for(size_t j=0;j<v.size();++j)L[v[j]].push_back(v[(j+1)%v.size()]),L[v[j]].push_back(v[(v.size()+j-1)%v.size()]);
        }
    for(int i=0;i<n;++i){
        printf("%d : ",i);
        for(size_t j=0;j<L[i].size();++j)printf("%d ",L[i][j]);
        printf("\n");
        }
    int minimo=1<<30;
    int ans=-1;
    for(size_t i=0;i<principal.size();++i){
        printf("principal : %d\n",principal[i]);
        bfs(principal[i]);
        int sum=0;
        for(size_t j=0;j<principal.size();++j){
            printf("%d : %d\n",principal[j],d[principal[j]]);
            sum+=d[principal[j]];
            }
        printf("\n");
        if(minimo>sum){
            minimo=sum;
            ans=principal[i];
            }
        else if(minimo==sum && principal[i]<ans)ans=principal[i];
        }
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
