#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[10][2][2];
int pow[15];
int m,a,b;
string toString(int n){
    string ans="";
    for(;n>0;n/=10){
        int d=n%10;
        ans=char(d+'0')+ans;
        }
    return ans;
    }

int toInt(const string &s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;++i)ans=ans*10+s[i]-'0';
    return ans;
    }
    
int f(int pos,bool equal,bool zero,const string &s,const int &d){
    if(pos==m)return 0;
    int &ret=dp[pos][equal][zero];
    if(ret>-1)return ret;
    int ans=0, end=9;
    if(equal)end=s[pos]-'0';
    for(int i=0;i<=end;++i){
        if(i==d && (d!=0 || !zero)){
            string aux=s.substr(pos+1);
            if(equal && i==end)ans+=toInt(aux)+1;
            else ans+=pow[m-1-pos];
            }
        ans+=f(pos+1,(equal && (i==end)),(zero && (i==0)),s,d);
        }
    return ret=ans;
    }

int g(int n,int d){
    if(n==0)return 0;
    string s=toString(n);
    m=s.length();
    for(int i=0;i<m;++i)memset(dp[i],-1,sizeof(dp[i]));
    return f(0,true,true,s,d);
    }
    
bool doit(){
    scanf("%d%d",&a,&b);
    if(a==0 && b==0)return false;
    for(int i=0;i<10;++i){
        int ans=g(b,i)-g(a-1,i);
        printf("%s%d",i==0?"":" ",ans);
        }
    printf("\n");
    return true;
    }
    
int main(){
    pow[0]=1;
    for(int i=1;i<=10;++i)pow[i]=pow[i-1]*10;
    while(1)if(!doit())break;
    }
