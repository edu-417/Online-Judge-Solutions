#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int n,m;
bool f(){
    for(int i=0,j=0;j<m;++j){
        if(s1[i]==s2[j])++i;
        if(i==n)return true;
        }
    return false;
    }
bool doit(){
    if(!(cin>>s1>>s2))return false;
    n=s1.length();
    m=s2.length();
    printf("%s\n",f()?"Yes":"No");
    return true;
    }
int main(){
    ios_base::sync_with_stdio(false);
    while(1)if(!doit())break;
    }
