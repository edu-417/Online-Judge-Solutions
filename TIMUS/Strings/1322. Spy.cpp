#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
char s[N+5];
int n,k;
int ind[N+5],pos[N+5],sa[N+5];
bool cmp(int x,int y){
    if(s[x]==s[y])return x<y;
    return s[x]<s[y];
    }
bool cmp2(int x,int y){
    return sa[x]<sa[y];
    }
int main(){
    scanf("%d",&k);--k;
    scanf("%s",s);
    for(n=0;s[n];++n)ind[n]=n;
    sort(ind,ind+n,cmp);
    sort(s,s+n);
    for(int i=0;i<n;++i)pos[ind[i]]=i;
    int idx=n-1;        
    for(int i=0;i<n;++i,--k)sa[idx]=k,idx=pos[idx];
    for(int i=0;i<n;++i)if(sa[i]<0)sa[i]+=n;
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,cmp2);
    for(int i=0;i<n;++i)putchar(s[ind[i]]);
    printf("\n");
    }
