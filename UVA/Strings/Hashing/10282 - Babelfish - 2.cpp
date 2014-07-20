#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef unsigned int hash;
char c[22],c1[11],c2[11];
#define N 1000000
vector<pair< hash , string> > M[N+5];
hash aux,d;
hash codeHash(const char *c){
    hash ans=0;
    for(;*c;++c)ans=(ans<<5)+ans+*c-'a';
    return ans;
    }
void doit(){
    while(1){
        gets(c);
        if(strcmp(c,"")==0)break;
        sscanf(c,"%s%s",c1,c2);
        aux=codeHash(c2);
        M[aux%N].push_back(make_pair(aux,string(c1)));
        }
    while(1){
        if(!gets(c))break;
        aux=codeHash(c);
        d=aux%N;
        if(M[d].size()==0)printf("eh\n");
        else{
            bool in=false;
            for(int i=0;i<M[d].size();++i){
                if(M[d][i].first==aux){
                    printf("%s\n",M[d][i].second.c_str());
                    in=true;break;
                    }
                }
            if(!in)printf("eh\n");
            }
        }
    }
int main(){
    doit();
    }
