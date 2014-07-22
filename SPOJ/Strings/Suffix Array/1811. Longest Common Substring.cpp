#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 250000
#define alphabet 256
char s[2*N+5],s1[N+5],s2[N+5];
int cnt[2*N+5],c[2*N+5],cn[2*N+5],p[2*N+5],pn[2*N+5],lcp[2*N+5];
    
void buildSuffix(){
    memset(cnt,0,sizeof(int)*alphabet);
    int n;
    for(n=0;s[n];++n)++cnt[ s[n] ];
    s[n]='@';++cnt[ s[n++] ];
    for(int i=1;i<alphabet;++i)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;++i)p[ --cnt[ s[i] ] ]=i;
    c[ p[0] ]=0;
    int classes=1;
    for(int i=1;i<n;++i){
        if( s[ p[i] ] > s[ p[i-1] ] )++classes;
        c[ p[i] ]=classes-1;
        }

    for(int h=0;(1<<h)<n;++h){
        //if(classes==n)break;
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

void buildLCP(){
    int k=0,n;
    for(n=0;s[n];++n)
        if(c[n]>0){
            int j=p[ c[n]-1 ];
            while(s[n+k]==s[j+k])++k;
            lcp[ c[n]-1 ]=k;
            if(k>0)--k;
            }
    lcp[n-1]=0;
    }
int main(){
    scanf("%s%s",s1,s2);
    int n,m;
    for(n=0;s1[n];++n)s[n]=s1[n];
    s[n++]='$';
    for(m=0;s2[m];++m)s[n+m]=s2[m];
    buildSuffix();
    buildLCP();
    int ans=0;
    for(int i=0;i<n+m+1;++i)
        if( (p[i]<n && p[i+1]>=n) || (p[i]>=n && p[i+1]<n) )
            if(ans<lcp[i])ans=lcp[i];
    printf("%d\n",ans);
    }
