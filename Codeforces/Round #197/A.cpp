#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char c[105];

int toInt(string s){
    int ans=0;
    for(int i=0;i<s.length();++i)ans=ans*10+s[i]-'0';
    return ans;
    }
bool doit(){
    if(scanf("%s",c)!=1)return false;
    string s(c);
    s+='+';
    int last=0;
    vector<int>v;
    for(int i=0;i<s.length();++i)if(s[i]=='+')v.push_back(toInt(s.substr(last,i-last))),last=i+1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)printf("%s%d",i==0?"":"+",v[i]);
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
