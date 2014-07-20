#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

map< vector< vector<int> > , int> M;
int d[362881],parent[362881],action[362881];
vector< vector<int> > start,end;
vector<int> pathAction;

bool doit(){
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j){
            scanf("%d",&end[i][j]);
            if(i==0 && j==0)if(end[i][j]==0)return false;
            }
    if(M.find(end)==M.end() || d[M[end]]==-1)printf("Not solvable\n");
    else{
        printf("%d ",d[M[end]]);
        pathAction.clear();
        for(int u=M[end];u!=-1;u=parent[u]){
            pathAction.push_back(action[u]);
            }
        for(size_t i=0;i<pathAction.size()-1;++i)printf("%s%d",pathAction[i]/3==0? "H":"V",pathAction[i]%3+1);
        printf("\n");
        }
    return true;
    }
    
int main(){
    int n=0;
    end.resize(3, vector<int> (3));
    start.resize(3, vector<int> (3));
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)start[i][j]=i*3+j+1;
    memset(d,-1,sizeof(d));
    memset(parent,-1,sizeof(parent));
    queue< vector < vector<int> > > Q;
    M[start]=n++;
    d[0]=0;
    Q.push(start);
    vector< vector <int> > u,to;
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int i=0;i<3;++i){
            to=u;
            for(int j=0;j<3;++j)to[i][j]=u[i][(j+1)%3];
            if(M.find(to)==M.end())M[to]=n++;
            if(d[M[to]]!=-1)continue;
            d[ M[to] ] =d[ M[u] ]+1;
            parent[M[to]]=M[u];
            action[M[to]]=i;
            Q.push(to);
            }
        for(int j=0;j<3;++j){
            to=u;
            for(int i=0;i<3;++i)to[(i+1)%3][j]=u[i][j];
            if(M.find(to)==M.end())M[to]=n++;
            if(d[M[to]]!=-1)continue;
            d[ M[to] ] =d[ M[u] ]+1;
            parent[M[to]]=M[u];
            action[M[to]]=j+3;
            Q.push(to);
            }
        }
    while(1)if(!doit())break;
    }
