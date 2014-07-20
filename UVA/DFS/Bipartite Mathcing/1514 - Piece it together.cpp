#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define NM 250000
#define N 500
#define M 500
char s[N+5][M+5];
int id[N+5][M+5];
int mt[NM+5],head[NM+5];
int To[(NM<<1)+5];
int next[(NM<<1)+5];
bool used[NM+5];

int n,m,C,edge;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void add_edge(int u,int to){
    To[edge]=to;
    next[edge]=head[u];
    head[u]=edge++;
    }
    
bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
    }
bool dfs(int u){
    if(used[u])return false;
    used[u]=true;
    for(int i=head[u];i!=-1;i=next[i]){
        int to=To[i];
        if(mt[to]==-1 || dfs(mt[to])){
            mt[to]=u;
            return true;
            }
        }
    return false;
    }
    
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",s[i]);
    int white=0,black=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)if(s[i][j]=='W')id[i][j]=white++;
        else if(s[i][j]=='B')id[i][j]=black++;
    
    if((black<<1)!=white){
        printf("NO\n");
        return;
        }
    edge=0;
    memset(head,-1,sizeof(int)*(black<<1));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(s[i][j]=='B'){
                for(int k=0;k<4;++k){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(!isValid(x,y))continue;
                    if(s[x][y]!='W')continue;
                    if(k<2)add_edge(id[i][j],id[x][y]);
                    else add_edge(id[i][j]+black,id[x][y]);
                    }
                }
    
    black<<=1;
    memset(mt,-1,sizeof(int)*white);
    
    bool ans=true;
    
    for(int i=0;i<black;++i){
        memset(used,false,sizeof(bool)*black);
        if(!dfs(i)){
            ans=false;
            break;
            }
        }    
    printf("%s\n",ans?"YES":"NO");
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
