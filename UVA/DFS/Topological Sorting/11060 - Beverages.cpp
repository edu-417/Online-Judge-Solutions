#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define N 105
map<string,int> M;
vector<int> order;
vector<int> L[N];
int in[N];
int n,m,caso=0;
char c[100],c1[100],c2[100];
string s[N];

bool doit(){
    if(scanf("%d",&n)!=1)return false;
    M.clear();
    for(int i=n-1;i>=0;--i)scanf("%s",c),s[i]=string(c),M[s[i]]=i;
    for(int i=0;i<n;++i)L[i].clear();
    memset(in,0,sizeof(int)*n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%s%s",c1,c2),L[M[string(c1)]].push_back(M[string(c2)]);
        ++in[M[string(c2)]];
        }
    order.clear();
    priority_queue<int> Q;
    for(int i=n-1;i>=0;--i)if(in[i]==0)Q.push(i);
    while(!Q.empty()){
        int u=Q.top();
        Q.pop();
        order.push_back(u);
        for(int i=L[u].size()-1;i>=0;--i){
            int to=L[u][i];
            --in[to];
            if(in[to]>0)continue;
            Q.push(to);
            }
        }
    printf("Case #%d: Dilbert should drink beverages in this order:",++caso);
    for(int i=0;i<n;++i)printf(" %s",s[order[i]].c_str());
    printf(".\n\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
