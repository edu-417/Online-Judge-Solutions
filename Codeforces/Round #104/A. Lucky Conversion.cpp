#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c1[100005],c2[100005];
int c[4];
int main(){
    scanf("%s%s",c1,c2);
    int d1=0,d2=0;
    for(int i=0;i<strlen(c1);++i)
        if(c1[i]=='4' && c2[i]=='7')d1++;
        else if(c1[i]=='7' && c2[i]=='4')d2++;
    int ans=max(d1,d2);
    printf("%d\n",ans);
    }
