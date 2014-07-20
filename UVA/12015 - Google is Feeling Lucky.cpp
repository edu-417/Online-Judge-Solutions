#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10
#define L 100
char s[N+5][L+5];
int r[N+5];
int caso,C;
void doit(){
    for(int i=0;i<N;++i)scanf("%s%d",s[i],r+i);
    int maxR=*max_element(r,r+N);
    printf("Case #%d:\n",++caso);
    for(int i=0;i<N;++i)if(r[i]==maxR)printf("%s\n",s[i]);
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
