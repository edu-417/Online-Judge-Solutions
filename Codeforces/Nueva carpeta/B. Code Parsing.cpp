#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000000
char s[N+5];
int cntX,cntY;
int main(){
    scanf("%s",s);
    for(int i=0;s[i];++i)if(s[i]=='x')++cntX;
    else ++cntY;
    int d=min(cntX,cntY);
    cntX-=d,cntY-=d;
    for(int i=0;i<cntX;++i)putchar('x');
    for(int i=0;i<cntY;++i)putchar('y');
    printf("\n");
    }
