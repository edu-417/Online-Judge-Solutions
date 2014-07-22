#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define N 200000
char s[N+5];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;++i)s[n+i]=s[i];n+=n;
    int ans=0;
    for(int i=0;i<n/2;){
        ans=i;
        int j=i+1,k=i;
        for(;j<n && s[k]<=s[j];++j)
            if(s[k]<s[j])k=i;
            else ++k;
        for(;i<=k;i+=j-k)printf("%s\n",string(s).substr(i,j-k).c_str());
        }
    printf("%d\n",ans);
    }
