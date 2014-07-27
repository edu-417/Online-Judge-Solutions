#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000
int n,mask;

int dp[N+5][12][12];
int next[N+5][12][12];
bool f(int pos,int dif,int last){
    if(pos==n)return true;
    int &ret=dp[pos][dif][last];
    if(ret>-1)return ret;
    bool ans=false;
    for(int i=0;i<10;++i)
        if((mask>>i)&1 && (10-i)>dif){
                if(10-i==last)continue;
                if(f(pos+1,10-i-dif,10-i)){
                    next[pos][dif][last]=10-i;
                    ans=true;
                    }
            }
    return ret=ans;
    }

void rec(){
    int dif=0,last=0;
    for(int i=0;i<n;++i){
        int d=next[i][dif][last];
        printf("%s%d",i==0?"":" ",d);
        dif=d-dif;
        last=d;
        }
    printf("\n");    
    }
char s[15];
bool doit(){
    if(scanf("%s",s)!=1)return false;
    mask=0;
    for(int i=0;s[i];++i){
        mask<<=1;
        if(s[i]=='1')mask^=1;
        }
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    memset(next,-1,sizeof(next));
    bool ans=f(0,0,0);
    printf("%s\n",ans?"YES":"NO");
    if(ans)rec();
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
