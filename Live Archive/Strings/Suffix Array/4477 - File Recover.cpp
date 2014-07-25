#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define alphabet 256
#define N 100000
char s[N+5];
int cnt[N+5],c[N+5],cn[N+5],p[N+5],pn[N+5],lcp[N+5];
bool doit(){
    scanf("%s",s);
    if(s[0]=='*')return false;
    memset(cnt,0,sizeof(int)*alphabet);
    int n;
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
        
    int k=0;
    for(int i=0;i<n;++i)
        if(c[i]>0){
            int j=p[ c[i]-1 ];
            while(s[i+k]==s[j+k])++k;
            lcp[ c[i]-1 ]=k;
            if(k>0)--k;
            }
    lcp[n-1]=0;
    int ans=0;
    for(int i=1;i<n;++i)
        if(lcp[i]>lcp[i-1])ans+=lcp[i]-lcp[i-1];
    cout<<ans<<endl;
    //printf WA :S  why live archive?
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
