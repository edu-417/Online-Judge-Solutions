#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int a,b,k;
string toString(int n){
    if(n==0)return "0";
    string ans="";
    for(;n>0;n/=10){
        int d=n%10;
        ans=char(d+'0')+ans;
        }
    return ans;
    }

int f(int n){
    string K=toString(k);
    int ans=0;
    for(int i=0;i<=n;++i){
        string s=toString(i);
        if(s.find(K)!=-1)++ans;
        }
    return ans;
    }
bool doit(){
    scanf("%d%d%d",&a,&b,&k);
    if(a==-1 && b==-1 && k==-1)return false;
    printf("%d %d %d : \n",a,b,k);
    int ans=f(b)-f(a-1);
    printf("%d\n",ans);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
