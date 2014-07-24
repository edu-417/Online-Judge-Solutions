#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100000
#define M 100
char s1[N+5],s2[M+5];
int next[N+5][256];

void buildNext(){
    int n=strlen(s1);
    for(int i='a';i<='z';++i)next[n][i]=-1;
    for(int i=n-1;i>=0;--i)
        for(int j='a';j<='z';++j)
            if(s1[i]==char(j))next[i][j]=i+1;
            else next[i][j]=next[i+1][j];
    }

int lastPosition(int pos){
    int ans=pos;
    for(int i=0;s2[i];++i)
        if(next[ans][s2[i]]==-1)return -1;
        else ans=next[ans][s2[i]];
    return ans;
    }
    
long long f(){
    int n=strlen(s1);
    long long ans=0;
    for(int i=0;s1[i];++i){
        int pos=lastPosition(i);
        if(pos==-1)continue;
        ans+=(n-pos+1);
        }
    return ans;
    }
    
int main(){
    scanf("%s%s",s1,s2);    
    buildNext();
    long long ans=f();
    printf("%lld\n",ans);
    }
