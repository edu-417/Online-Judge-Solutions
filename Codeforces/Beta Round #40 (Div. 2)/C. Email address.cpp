#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char c[1000];
int main(){
    scanf("%s",c);
    string s(c);
    string ans="";
    int n=strlen(c);
    int inicio=0,fin=n;
    if(s.substr(0,3)=="dot")inicio=3;
    if(s.substr(n-3)=="dot")fin=n-3;
    if(s.substr(0,2)=="at")inicio=2;
    if(s.substr(n-2)=="at")fin=n-2;
    
    string aux="";
    bool at=false;
    if(inicio==3)ans="dot";
    else if(inicio==2)ans="at";
    for(int i=inicio;i<fin;){
        if(i+3<=fin && s.substr(i,3)=="dot")aux=".",i+=3;
        else if(!at && i+2<=fin && s.substr(i,2)=="at")aux="@",i+=2,at=true;
        else aux=s[i],++i;
        ans+=aux;
        }
    if(fin==n-3)ans+="dot";
    else if(fin==n-2)ans+="at";
    printf("%s\n",ans.c_str());
    }
