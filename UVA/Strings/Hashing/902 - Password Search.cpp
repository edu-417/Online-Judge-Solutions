#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define L 1000000
#define N 10
typedef unsigned long long hash;
char c[L+2];
hash pow[N+2];
int n;
map<hash,int> M;
bool doit(){
    if(scanf("%d%s",&n,&c)!=2)return false;
    M.clear();
    hash code=0;
    for(int i=0;i<n;++i)code=(code<<5)+c[i]-'a';
    M[code]++;
    for(int i=n;c[i];++i){
        code-=(c[i-n]-'a')*pow[n-1];
        code=(code<<5)+c[i]-'a';
        M[code]++;
        }
    int best=0;
    hash codeHash=0;
    for(map<hash,int> ::iterator it=M.begin(); it!=M.end();++it)
        if(it->second>best)best=it->second,codeHash=it->first;
    string ans="";
    for(int i=0;i<n;++i)ans=char((codeHash&((1<<5)-1))+'a')+ans,codeHash>>=5;
    printf("%s\n",ans.c_str());
    return true;
    }
int main(){
    pow[0]=1;
    for(int i=1;i<=N;++i)pow[i]=(pow[i-1]<<5);
    while(1)if(!doit())break;
    }
