#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000
char s[N+5];
int z[N+5];
int C,n,q,x;
void doit(){
    scanf("%s",s);
    int n=strlen(s);
    reverse(s,s+n);
    z[0]=0;
    for(int i=1,l=0,r=0;i<n;++i){
        z[i]=0;
        if(i<=r)z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])++z[i];
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
        }
    z[0]=n;
    scanf("%d",&q);
    for(int i=0;i<q;++i)scanf("%d",&x),printf("%d\n",z[n-x]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
