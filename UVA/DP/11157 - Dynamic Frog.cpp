#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
#define N 100
#define oo (1<<30)
int dp[N+5][N+5][N+5];
int n,d,C,caso;
int a[N+5];
char type[N+5];
int f(int pos,int last1,int last2){
    if(pos==n+1)return max(a[pos]-a[last1],a[pos]-a[last2]);
    int &ret=dp[pos][last1][last2];
    if(ret>-1)return ret;
    int f2=oo,f1=oo;;
    if(type[pos]=='S')f1=max(f(pos+1,pos,last2),a[pos]-a[last1]);
    else{
        f1=max(f(pos+1,pos,pos),a[pos]-a[last1]);
        f1=max(f1,a[pos]-a[last2]);
        }
    if(type[pos]=='S')f2=max(f(pos+1,last1,pos),a[pos]-a[last2]);
    int ans=min(f1,f2);
    return ret=ans;
    }

int toInt(const string &s){
    int ans=0;
    for(int i=0;i<s.length();++i)ans=ans*10+s[i]-'0';
    return ans;
    }
int parse(const string &s){
    return toInt(s.substr(2));
    }
    
char c[100];
void doit(){
    scanf("%d%d",&n,&d);
    a[0]=0,a[n+1]=d;
    for(int i=1;i<=n;++i){
        scanf("%s",c);
        type[i]=c[0];
        a[i]=parse(c);
        }
    memset(dp,-1,sizeof(dp));
    int ans=f(1,0,0);
    printf("Case %d: %d\n",++caso,ans);
    }
    
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
