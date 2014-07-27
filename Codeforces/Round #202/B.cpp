#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 1000000
int n;
int a[15];
int dp[N+5];
int r[N+5];

void rec(int n){
    int l=dp[n];
    string ans="";
    for(int i=0;i<l;++i){
        ans+=char(r[n]+'0');
        n-=a[r[n]];
        }
    printf("%s\n",ans.c_str());
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=1;i<10;++i)scanf("%d",a+i);
    
    for(int i=0;i<=n;++i){
        dp[i]=0;
        for(int j=1;j<10;++j)if(a[j]<=i){
            int aux=dp[i-a[j]]+1;
            if(aux==dp[i]){
                if(j>r[i])r[i]=j;
                }
            else if(aux>dp[i])dp[i]=aux,r[i]=j;
            }
        }
    if(dp[n]==0)printf("-1\n");
    else{
        rec(n);
        }
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
