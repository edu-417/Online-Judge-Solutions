#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100

vector<int> L[N+5];

bool used[N+5];
int ini[256],fin[256],mt[N+5],left[N+5];
char s[N+5],c[10];
int n,m,C;
bool dfs(int u){
    if(used[u])return false;
    used[u]=true;
    for(int i=0;i<L[u].size();++i){
        int to=L[u][i];
        if(mt[to]==-1 || dfs(mt[to])){
            mt[to]=u;
            return true;
            }
        }
    return false;
    }


bool match(int idx){
    memset(mt,-1,sizeof(mt));
    for(int i=0;i<n;++i){
        memset(used,false,sizeof(used));
        if(!dfs(i))return false;
        }
    return true;
    }

void doit(){
    scanf("%s",s);
    n=strlen(s);
    sort(s,s+n);
    memset(ini,-1,sizeof(ini));
    memset(fin,-1,sizeof(fin));
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i){
        if(ini[s[i]]==-1)ini[s[i]]=i;
        fin[s[i]]=i;
        }
        
    for(int i=0;i<n;++i){
        scanf("%s",c);
        m=strlen(c);
        sort(c,c+m);
        for(int j=0;j<m;++j)
            for(int k=ini[s[j]];k<=fin[s[j]];++k)L[i].push_back(k);
        }
    bool solution=match();
    if(!solution)printf("NO SOLUTION\n");
    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<L[i].size();++j){
                int to=L[i][j];
                if(!used2[to] && mtc)
                }
            }
        
        for(int i=0;i<n;++i)left[mt[i]]=i;
        for(int i=0;i<n;++i)printf("%c",s[left[i]]);
        printf("\n");
        }
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
