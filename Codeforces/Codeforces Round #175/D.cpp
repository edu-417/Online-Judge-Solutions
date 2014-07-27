#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
int b[N+5],a[N+5];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)b[i]=i,a[i]=i;
    int c[n];
    int ans=0;
    do{
        for(int i=0;i<n;++i)c[i]=(a[i]+b[i])%n;
        sort(c,c+n);
        bool val=true;
        for(int i=0;i<n;++i)if(c[i]!=i)val=false;
        ans+=val;
        }while(next_permutation(b,b+n));
    printf("%d\n",ans);
    }
