#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    if(n>m){
        for(int i=0;i<m;++i)putchar('B'),putchar('G');
        for(int i=m;i<n;++i)putchar('B');
        }
    else{
        for(int i=0;i<n;++i)putchar('G'),putchar('B');
        for(int i=n;i<m;++i)putchar('G');
        }
    printf("\n");
    }
