#include<cstdio>
#include<cstring>
#define N 1000000
char s1[N+5],s2[N+5];
int main(){
    scanf("%s%s",s1,s2);
    int cnt1=0,cnt2=0;
    for(int i=0;s1[i];++i)if(s1[i]=='1')++cnt1;
    for(int i=0;s2[i];++i)if(s2[i]=='1')++cnt2;
    if(strlen(s1)!=strlen(s2))printf("NO\n");
    else if(strcmp(s1,s2)==0)printf("YES\n");
    else if(cnt1==0 || cnt2==0)printf("NO\n");
    else printf("YES\n");
    }
