#include<cstdio>
#define N 1000000
int border[N+5];
char pattern[N+5],text[N+5];
int n,caso=0;
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    scanf("%s%s",pattern,text);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(j>0 && pattern[i]!=pattern[j])j=border[j-1];
        if(pattern[i]==pattern[j])++j;
        border[i]=j;
        }
    int ans=0;
    int j=0;
    if(caso>0)printf("\n");
    for(int i=0;text[i];++i){
        while(j>0 && text[i]!=pattern[j])j=border[j-1];
        if(text[i]==pattern[j])++j;
        if(j==n){
            ++ans;
            printf("%d\n",i-n+1);
            j=border[j-1];
            }
        }
    ++caso;
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
