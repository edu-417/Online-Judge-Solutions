#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100
#define M 100
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int a[N+5][M+5];
int ans[N+5][M+5];
bool used[N*M+5];
vector<int> L[N*M+5];
int mt[N*M+5];
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
int r,c;

bool isValid(int x,int y){
    return x>=0 && x<r && y>=0 && y<c;
    }
int main(){
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)scanf("%d",a[i]+j);
    for(int i=0;i<r;++i)
        for(int j=(i&1);j<c;j+=2){
            int u=(i*c+j)/2;
            for(int k=0;k<4;++k){
                int x=i+dx[k];
                int y=j+dy[k];
                if(!isValid(x,y))continue;
                if(a[i][j]==a[x][y])continue;
                int to=(x*c+y)/2;
                L[u].push_back(to);
                }
            }
    int n=r*c/2;
    int m=n;    
    memset(mt,-1,sizeof(int)*(m));
    
    for(int i=0;i<n;++i){
        memset(used,false,sizeof(bool)*n);
        dfs(i);
        }
    bool sol=true;
    for(int i=0;i<m;++i)if(mt[i]==-1)sol=false;
    else{
        //printf("%d %d\n",mt[i],i);
        int x=mt[i]/(c/2);
        int y=(2*mt[i]+(x&1))%c;
        ans[x][y]=i+1;
        x=i/(c/2);
        y=(2*i+(!(x&1)))%c;
        ans[x][y]=i+1;
        }
    
    if(!sol)printf("-1\n");
    else{
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j)printf("%s%d",j==0?"":" ",ans[i][j]);
            printf("\n");
            }
        }
    }
