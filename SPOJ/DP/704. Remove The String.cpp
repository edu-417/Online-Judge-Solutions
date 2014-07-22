#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10000
#define M 1000

char s1[N+5],s2[M+5];
int border[M+5];
int dp[N+5][M+5];
int n,m;
void buildBorder(char *s){
    border[0]=0;
    for(int i=1;s[i];++i){
        int j=border[i-1];
        while(j>0 && s[i]!=s[j])j=border[j-1];
        if(s[i]==s[j])++j;
        border[i]=j;
        }
    }

int f(int pos1,int pos2){
    if(pos2==m)return 1+f(pos1,m-1);
    if(pos1==n)return 0;
    int &ret=dp[pos1][pos2];
    if(ret>-1)return ret;
    int ans=1+f(pos1+1,pos2);
    int j=pos2;
    while(j>0 && s1[pos1]!=s2[j])j=border[j-1];
    if(s1[pos1]==s2[j])ans=min(ans,f(pos1+1,j+1));
    else ans=min(ans,f(pos1+1,j));
    return ret=ans;
    }
bool doit(){
    if(scanf("%s%s",s1,s2)!=2)return false;;
    n=strlen(s1);
    m=strlen(s2);
    buildBorder(s2);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",f(0,0));
    }
int main(){
    while(1)if(!doit())break;
    }
