#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
typedef unsigned int hash;
char c[22],c1[12],c2[12];
map<hash,string> M;

hash codeHash(const char *c){
    hash ans=0;
    for(int i=0;c[i];++i)ans=(ans<<5)+ans+c[i]-'a';
    return ans;
    }
void doit(){
    while(1){
        gets(c);
        if(strcmp(c,"")==0)break;
        sscanf(c,"%s%s",c1,c2);
        M[codeHash(c2)]=string(c1);
        }
    while(1){
        if(!gets(c))break;
        if(M.find(codeHash(c))==M.end())printf("eh\n");
        else printf("%s\n",M[codeHash(c)].c_str());
        }
    }
int main(){
    doit();
    }
