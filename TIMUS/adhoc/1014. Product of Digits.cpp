#include<cstdio>
#include<string>
using namespace std;
int n;
string f(int n){
    if(n==0)return "10";
    if(n==1)return "1";
    string ans="";
    for(int i=9;i>=2;--i){
        for(;n%i==0;n/=i)ans=char(i+'0')+ans;
        }
    if(n>1)return "-1";
    return ans;
    }
int main(){
    scanf("%d",&n);
    string ans=f(n);
    printf("%s\n",ans.c_str());
    }
