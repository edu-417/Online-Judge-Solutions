#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
#define L 1000000
#define N 10
typedef unsigned long long hash;
char c[L+2];
hash pow[N+2];
int n,best;
string ans;
hash code,d,codeHash;
bool in;
vector<pair<hash,int> >M[L];
bool doit(){
    if(scanf("%d%s",&n,&c)!=2)return false;
    for(int i=0;i<L;++i)M[i].clear();
    code=0;
    for(int i=0;i<n;++i)code=(code<<5)+c[i]-'a';
    d=code%L;
    in=false;
    for(int i=0;i<M[d].size();++i)
        if(M[d][i].first==code)M[d][i].second++,in=true;
    if(!in)M[d].push_back(make_pair(code,1));
    for(int i=n;c[i];++i){
        code-=(c[i-n]-'a')*pow[n-1];
        code=(code<<5)+c[i]-'a';
        in=false;
        d=code%L;
        for(int i=0;i<M[d].size();++i)
            if(M[d][i].first==code)M[d][i].second++,in=true;
        if(!in)M[d].push_back(make_pair(code,1));
        }
    best=0;
    codeHash=0;
    for(int i=0;i<L;++i)
        for(int j=0;j<M[i].size();++j){
            if(M[i][j].second>best)best=M[i][j].second,codeHash=M[i][j].first;
            }
    ans="";
    for(int i=0;i<n;++i)ans=char((codeHash&((1<<5)-1))+'a')+ans,codeHash>>=5;
    printf("%s\n",ans.c_str());
    return true;
    }
int main(){
    pow[0]=1;
    for(int i=1;i<=N;++i)pow[i]=(pow[i-1]<<5);
    while(1)if(!doit())break;
    }
