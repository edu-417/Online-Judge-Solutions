#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
#define N 10
int n;
char s[N+5][N+5];
int B[N+5],C[N+5];
bool dig[10];
string num(int x){
    string ans="";
    for(int i=0;i<4;++i){
        int d=x%10;
        x/=10;
        ans=char(d+'0')+ans;
        }
    return ans;
    }
bool valid(string c){
    for(int i=0;i<10;++i)dig[i]=false;
    for(int i=0;i<4;++i)if(dig[c[i]-'0'])return false;
    else dig[c[i]-'0']=true;
    return true;
    }

bool f(string c){
    for(int i=0;i<10;++i)dig[i]=false;
    for(int i=0;i<4;++i)dig[c[i]-'0']=true;
    for(int i=0;i<n;++i){
        int cntB=0,cntC=0;
        for(int j=0;j<4;++j)if(c[j]==s[i][j])++cntB;
        for(int j=0;j<4;++j)if(c[j]!=s[i][j] && dig[s[i][j]-'0'])++cntC;
        if(cntB!=B[i] || cntC!=C[i])return false;
        }
    return true;
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s%d%d",s[i],B+i,C+i);
    int cnt=0;
    string ans="";
    for(int i=0;i<10000;++i){
        string S=num(i);
        if(valid(S) && f(S))++cnt,ans=S;
        }
    if(cnt==0)printf("Incorrect data\n");
    else if(cnt==1)printf("%s\n",ans.c_str());
    else printf("Need more data\n");
    }
