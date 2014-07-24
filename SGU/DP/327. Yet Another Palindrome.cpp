#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 14
#define oo 1<<30
string s[N+5];
int dp[(1<<N)+5][N+5],next[(1<<N)+5][N+5];
int L[N+5];
int common[N+5][N+5];
int n;
char cad[50];
int dfs(int mask,int start){
    if(mask==(1<<start))return L[start]; 
    int &ret=dp[mask][start];
    if(ret!=-1)return ret;
    int ans=oo;
    for(int i=0;i<n;++i)
        if( (mask>>i)&1 && i!=start){
            int aux=dfs( mask^(1<<start), i) - common[start][i] ;
            if(aux<ans)ans=aux,next[mask][start]=i;
            }
    ans+=L[start];
    return ret=ans;
    }

string rec(int mask,int start){
    string ans=s[start];
    for(;mask>0;){
        int new_start=next[mask][start];
        mask^=(1<<start);
        ans+=s[new_start].substr(common[start][new_start]);
        start=new_start;
        }
    return ans;
    }
int c(string &s1,string &s2){
    int n=s1.length();
    int m=s2.length();    
    for(int i=0;i<n;++i){
        if(n-i>m)continue;
        if( s1.substr(i) == s2.substr(0,n-i) )return n-i;
        }
    return 0;
    }

string palindrome(string &s1){
    }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",cad),s[i]=string(cad);
    for(int i=0;i<n;++i)L[i]=s[i].length();   
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)common[i][j]=c(s[i],s[j]);
    int ans=oo;
    memset(dp,-1,sizeof(dp));
    int start;
    for(int i=0;i<n;++i){
        int aux=dfs( (1<<n)-1,i );
        if(aux<ans)ans=aux,start=i;
        }
    string ansS=rec((1<<n)-1,start);
    ansS=palindrome(ansS);
    printf("%s\n",ansS.c_str());
    }
