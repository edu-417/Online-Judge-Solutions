#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define N 205
map<string,int> M;
vector<int> L[N];
char c[25],c1[15],c2[15];
int d[N][N];
int n,C,u,to;
string s[N];
bool f(string s1,string s2){
    size_t n1=s1.length();
    size_t n2=s2.length();
    if(n1 != n2)return false;
    int ct=0;
    for(size_t i=0;i<n1;++i)if(s1[i]!=s2[i])++ct;
    if(ct==1)return true;
    return false;
    }
    
void doit(){
    M.clear();
    n=0;
    while(1){
        scanf("%s",c);
        s[n]=string(c);
        if(s[n]=="*")break;
        M[s[n]]=n;
        ++n;
        }
    for(int i=0;i<n;++i)L[i].clear();
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(f(s[i],s[j]))L[i].push_back(j),L[j].push_back(i);
    for(int i=0;i<n;++i)memset(d[i],-1,sizeof(int)*n);
    queue<int> Q;
    for(int i=0;i<n;++i){
        d[i][i]=0;
        Q.push(i);
        while(!Q.empty()){
            u=Q.front();
            Q.pop();
            for(size_t j=0;j<L[u].size();++j){
                to=L[u][j];
                if(d[i][to]!=-1)continue;
                d[i][to]=d[i][u]+1;
                Q.push(to);
                }
            }
        }
    gets(c);
    int ans;
    while(1){
        if(!gets(c))break;
        if(string(c)=="")break;
        sscanf(c,"%s%s",c1,c2);
        ans=d[ M[string(c1)] ][ M[string(c2)] ];
        printf("%s %s %d\n",c1,c2,ans);
        }
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i){
        printf("%s",i==0?"":"\n");
        doit();
        }
    }
