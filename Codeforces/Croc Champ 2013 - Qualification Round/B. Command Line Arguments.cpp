#include<cstdio>
#include<vector>
#include<string>
using namespace std;
#define N 100000
char s[N+5];
int main(){
    gets(s);
    printf("%s\n",s);
    string aux="";
    vector<string> ans;
    bool open=true;
    bool space=false;
    bool val=false;
    for(int i=0;s[i];++i){
        if(open){
            if(s[i]=='"'){
                open=false;
                ans.push_back(aux);
                aux="";
                }
            else aux+=s[i];
            }
        else{
            if(s[i]=='"')open=true;
            else if(s[i]==' '){
                if(!space){
                    aux="";
                    ans.push_back(aux);
                    }
                space=true;
                continue;
                }
            else aux+=s[i];
            }
        }
    for(int i=0;i<ans.size();++i)printf("<%s>\n",ans[i].c_str());
    }
