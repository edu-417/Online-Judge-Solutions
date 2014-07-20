#include<cstdio>
#include<algorithm>
using namespace std;
char s[100];
int n,m,C;
void doit(){
    scanf("%s%d%d",s,&n,&m);
    if(n>m)swap(n,m);
    if(s[0]=='r' || s[0]=='Q')printf("%d\n",n);
    else if(s[0]=='k')printf("%d\n",n*m/2+((n*m)&1));
    else printf("%d\n",(n/2+(n&1))*(m/2+(m&1)));
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
