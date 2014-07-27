#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char c1[205],c2[205];
vector<string> v;
int n;
void pwd(){
    printf("/");
    for(int i=0;i<v.size();i++)printf("%s",v[i].c_str());
    printf("\n");
    }
void cd(){
    string s(c2);
    s+="/";
    if(s[0]=='/')v.clear(),s.erase(s.begin());
    int ant=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            string aux=s.substr(ant,(i-ant));
            if(aux=="..")v.pop_back();
            else aux+="/",v.push_back(aux);
            ant=i+1;
            }
        }
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",c1);
        if(string(c1)=="pwd")pwd();
        else scanf("%s",c2),cd();
        }
    }
