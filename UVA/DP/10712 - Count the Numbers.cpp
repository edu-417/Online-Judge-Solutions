#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a,b,k,n,m;
int dp[15][4][2][2];
int pow[15];

string toString(int n){
    if(n==0)return "0";
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
    
int getBorder(const string &s){
    int n=s.length();
    for(int i=1;i<n;++i)if(s.substr(i)==s.substr(0,n-i))return n-i;
    return 0;
    }

int f(int pos,int pos2,bool equal,bool zero,const string &s,const string &s2){
    if(pos2==m){
        if(s2=="0" && zero)return f(pos,0,equal,zero,s,s2);
        if(equal)return toInt(s.substr(pos))+1;
        else return pow[n-pos];
        }
    if(pos==n)return 0;
    int &ret=dp[pos][pos2][equal][zero];
    if(ret>-1)return ret;
    int ans=0,end=9;
    if(equal)end=s[pos]-'0';
    for(int i=0;i<=end;++i){
        int j=pos2;
        while(j>0 && s2[j]-'0'!=i)j=getBorder(s2.substr(0,j));
        if(s2[j]-'0'==i)++j;
        ans+=f(pos+1,j,equal && i==end, zero && i==0,s,s2);
        }
    return ret=ans;
    }

int g(int x){
    if(x<k)return 0;
    if(x<0)return 0;
    string s=toString(x);
    n=s.length();
    string s2=toString(k);
    m=s2.length();
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)memset(dp[i][j],-1,sizeof(dp[i][j]));
    return f(0,0,true,true,s,s2)+(k==0);
    }
    
bool doit(){
    scanf("%d%d%d",&a,&b,&k);
    if(a==-1 && b==-1 && k==-1)return false;
    int ans=g(b)-g(a-1);
    printf("%d\n",ans);
    return true;
    }
int main(){
    pow[0]=1;
    for(int i=1;i<=10;++i)pow[i]=10*pow[i-1];
    while(1)if(!doit())break;
    }
