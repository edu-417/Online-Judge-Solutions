#include<cstdio>
#include<cstring>
#define N 100000
char text[N+5];
int border[N+5];
bool doit(){
    if(scanf("%s",text)!=1)return false;
    int n=strlen(text);
    int pos=0;
    for(int i=1,k=n-2;i<n;++i,--k){
        int j=border[i-1];
        while(j>0 && text[k]!=text[n-1-j])j=border[j-1];
        if(text[k]==text[n-1-j])++j;
        border[i]=j;
        }
    int j=0;
    printf("%s",text);
    for(int i=0;i<n;++i){
        while(j>0 && text[i]!=text[n-1-j])j=border[j-1];
        if(text[i]==text[n-1-j])++j;
        if(i==n-1){
            for(int k=j;k<n;++k)putchar(text[n-1-k]);
            }
        }
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
