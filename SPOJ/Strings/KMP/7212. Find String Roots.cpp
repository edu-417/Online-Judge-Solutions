#include<cstdio>
#include<cstring>
#define N 100000
char s[N+5];
int border[N+5];
bool doit(){
    scanf("%s",s);
    if(s[0]=='*')return false;
    int n=strlen(s);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(j>0 && s[i]!=s[j])j=border[j-1];
        if(s[i]==s[j])++j;
        border[i]=j;
        }
    if(n%(n-border[n-1])==0)printf("%d\n",n/(n-border[n-1]));
    else printf("1\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
