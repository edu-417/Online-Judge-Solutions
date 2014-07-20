#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
bool b[256],used[256];
vector<int> L[256];
vector<int> order;
vector<string> v;
char c[30];
void dfs(int u){
    if(used[u])return;
    used[u]=true;
    for(size_t i=0;i<L[u].size();++i){
        int to=L[u][i];
        dfs(to);
        }
    order.push_back(u);
    }
int main(){
    while(1){
        scanf("%s",c);
        if(c[0]=='#')break;
        string s(c);
        for(int i=0;i<s.length();++i)b[s[i]]=true;
        v.push_back(s);
        }
    for(int i=0;i<v.size()-1;++i)
        for(int j=0;j<v[i].length() && j<v[i+1].length();++j){
            if(v[i][j]==v[i+1][j])continue;
            L[v[i][j]].push_back(v[i+1][j]);
            break;
            }
    for(int i=0;i<256;++i)if(b[i])dfs(i);
    for(size_t i=order.size()-1;i>0;--i)putchar(char(order[i]));
    if(order.size()>0)putchar(char(order[0]));
    printf("\n");
    }
