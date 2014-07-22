#include<cstdio>
#include<vector>
using namespace std;
#define N 7163
vector<int> L[N+5];
int c[2],group[N+5];
int n,m,y;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j)scanf("%d",&y),L[i].push_back(--y);
        }
    bool ok=false;
    for(int k=0;k<n;++k){
        if(ok)break;
        ok=true;
        for(int u=0;u<n;++u){
            int cnt=0;
            for(int j=0;j<L[u].size();++j){
                int to=L[u][j];
                if(group[to]==group[u])++cnt;
                }
            if(cnt>1){
                group[u]=1-group[u];
                ok=false;
                }
            }
        }
    
    for(int i=0;i<n;++i)++c[group[i]];
    int ans=group[0];
    if(c[0]<c[1])ans=0;
    if(c[1]<c[0])ans=1;
    vector<int> path;
    for(int i=0;i<n;++i)if(group[i]==ans)path.push_back(i+1);
    printf("%d\n",path.size());
    for(int i=0;i<path.size();++i)printf("%s%d",i==0?"":" ",path[i]);
    printf("\n");
    }
