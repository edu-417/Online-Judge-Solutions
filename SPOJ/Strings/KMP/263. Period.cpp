#include<cstdio>
#define N 1000000
int n;
char s[N+5];
int border[N+5];
int C,caso=0;
void doit(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(j>0 && s[i]!=s[j])j=border[j-1];
        if(s[i]==s[j])++j;
        border[i]=j;
        }
    printf("Test case #%d\n",++caso);
    for(int i=1;i<n;++i){
        if(border[i]>0 && (i+1)%(i+1-border[i])==0)
            printf("%d %d\n",i+1,(i+1)/(i+1-border[i]));
        }
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
