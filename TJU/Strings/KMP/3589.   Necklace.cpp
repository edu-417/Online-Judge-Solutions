#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10000
#define M 1000
#define oo 1<<20
char s1[N+5],s2[N+5];
int border[N+5];
int b[N+5][256];
int dp[N+5][M+5];
int C;
int getBorder(char *s,int idx,char c){
    int j=idx;
    while(j>0 && c!=s[j])j=border[j-1];
    if(c==s[j])++j;
    return j;
    }
void buildBorder(char *s){
    border[0]=0;
    for(int i=1;s[i];++i){
        int j=border[i-1];
        while(j>0 && s[i]!=s[j])j=border[j-1];
        if(s[i]==s[j])++j;
        border[i]=j;
        }
    }

int f(){
    int n=strlen(s1);
    int m=strlen(s2);
    for(int i=0;i<=n;++i)dp[i][m]=oo;
    for(int i=0;i<m;++i)dp[n][i]=0;
    
    for(int i=n-1;i>=0;--i)
        for(int j=0;j<m;++j)dp[i][j]=min(1+dp[i+1][j],dp[i+1][b[j][s1[i]]]);
    }
void doit(){
    scanf("%s%s",s1,s2);
    buildBorder(s2);
    for(int i=0;s2[i];++i)
        for(int j='a';j<='z';++j)b[i][j]=getBorder(s2,i,j);
    f();
    printf("%d\n",dp[0][0]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
