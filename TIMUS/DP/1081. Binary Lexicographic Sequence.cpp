#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 50
int dp[N+5][2];
int n,k;
void g(){
    dp[n][false]=dp[n][true]=1;
    for(int i=n-1;i>=0;--i)
        dp[i][true]=dp[i+1][false],
        dp[i][false]=dp[i+1][true]+dp[i+1][false];
    }
string f(int n,int k){
    g();
    string ans="";
    if(dp[0][0]<k)return ans;
    for(int i=0;i<n;++i){
        if(dp[i+1][0]>=k)ans+='0';
        else{
            k-=dp[i+1][0];
            ans+='1';
            }
        }
    return ans;
    }
    
int main(){
    scanf("%d%d",&n,&k);
    string ans=f(n,k);
    if(ans.length()==0)printf("-1\n");
    else printf("%s\n",ans.c_str());
    }
