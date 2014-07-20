#include<cstdio>
#define N 1000000
char s[N+5];
int border[N+5];
bool doit(){
    scanf("%s",s);
    if(s[0]=='.')return false;
    int n=0;
    for(n=1;s[n];++n){
        int j=border[n-1];
        while(j>0 && s[n]!=s[j])j=border[j-1];
        if(s[n]==s[j])++j;
        border[n]=j;
        }
    if(n%(n-border[n-1])==0)printf("%d\n",n/(n-border[n-1]));
    else printf("1\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
