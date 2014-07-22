#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//Suffix Array O(nlogn)

#define alphabet 256
#define N 50000
char s[N+5];
int cnt[N+5],c[N+5],cn[N+5],p[N+5],pn[N+5],lcp[N+5];
int n;
void build_suffix(){
    memset(cnt,0,sizeof(int)*alphabet);
    for(n=0;s[n];++n)++cnt[ s[n] ];
    s[n]='$';++cnt[ s[n++] ];
    for(int i=1;i<alphabet;++i)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;++i)p[ --cnt[ s[i] ] ]=i;
    c[ p[0] ]=0;
    int classes=1;
    for(int i=1;i<n;++i){
        if( s[ p[i] ] > s[ p[i-1] ] )++classes;
        c[ p[i] ]=classes-1;
        }

    for(int h=0;(1<<h)<n;++h){
        for(int i=0;i<n;++i){
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0)pn[i]+=n;
            }
        memset(cnt,0,sizeof(int)*classes);
        for(int i=0;i<n;++i)++cnt[ c[ i ] ];
        for(int i=1;i<classes;++i)cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;--i)p[ --cnt[ c[ pn[i] ] ] ] = pn[i];
        cn[p[0]]=0;
        classes=1;
        for(int i=1;i<n;++i){
            int mid1=p[i]+(1<<h),mid2=p[i-1]+(1<<h);
            if(mid1>=n)mid1-=n;
            if(mid2>=n)mid2-=n;
            if(c[ p[i] ] > c[ p[i-1] ] || c[mid1]>c[mid2])++classes;
            cn[p[i]]=classes-1;
            }
        memcpy(c,cn,sizeof(int)*n);
        }
    }

void build_lcp(){
    int k=0;
    for(int i=0;i<n;++i)
        if(c[i]>0){
            int j=p[ c[i]-1 ];
            while(s[i+k]==s[j+k])++k;
            lcp[ c[i]-1 ]=k;
            if(k>0)--k;
            }
    lcp[n-1]=0;
    }

void doit(){
    scanf("%s",s);
    build_suffix();
    build_lcp();
    long long ans=(long long)n*(n-1)/2;
    for(int i=0;i<n;++i)ans-=lcp[i];
    printf("%lld\n",ans);
    //numero de distintos substrings Sum(n-p[i])-Sum(lcp[i]);
    //numero de distintos substrings que aparecen al menos 2 veces Sum(max(0,lcp[i]-lcp[i-1]))
    }
int C;
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }

//
