#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000000
char s[N+5];
int z[N+5];
int q,C,x,n;
void doit(){
    scanf("%s",s);
    n=strlen(s);
    //reverse(s,s+n);
    z[0]=0;
    for(int i=1,l=0,r=0;i<n;++i){
        z[i]=0;
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[ n-1-i-z[i] ] == s[ n-1-z[i] ])++z[i];//reverse xD
        if(i+z[i]-1>r)r=i+z[i]-1,l=i;
        }
    z[0]=n;
    scanf("%d",&q);
    for(int i=0;i<q;++i)scanf("%d",&x),printf("%d\n",z[n-x]);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
