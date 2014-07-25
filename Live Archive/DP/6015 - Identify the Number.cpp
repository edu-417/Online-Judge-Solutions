#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
#define N 1000
#define oo (1<<10)
int C,r,q,n,L;
char s[N+5];
int dp[N+5][N+5][2];

int f(){
    for(int j=0;j<q;++j)dp[n][j][0]=-oo,dp[n][j][1]=-oo;
    dp[n][r][0]=dp[n][r][1]=0;
    for(int i=n-1;i>=0;--i)
        for(int j=0;j<q;++j)
            for(int k=0;k<2;++k){
                int ans=dp[i+1][j][k];
                if(!k || s[i]>'0')ans=max(ans,1+dp[i+1][(j*10+s[i]-'0')%q][false]);
                dp[i][j][k]=ans;
                }
    }

void rec(){
    int pos=0,rem=0,zero=true;
    string ans="";
    for(int i=L;i>=1;--i){
        int d=-1,newrem=-1,newpos=-1;
            for(int j=pos;j<n;++j)if(dp[j][rem][zero]==i && dp[j+1][(rem*10+s[j]-'0')%q][false]==i-1 && s[j]>d)d=s[j],newrem=(rem*10+s[j]-'0')%q,newpos=j+1;
        pos=newpos,rem=newrem,zero=false;
        ans+=char(d);
        }
    printf("%s\n",ans.c_str());
    }
    
void doit(){
    scanf("%s%d%d",&s,&r,&q);
    n=strlen(s);
    f();
    L=dp[0][0][true];
    if(L>0)rec();
    else printf("Not found\n");
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
