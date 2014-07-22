#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define alphabet 1026
#define N 101000
char s[N+5];
int cnt[N+5],c[N+5],cn[N+5],p[N+5],pn[N+5],lcp[N+5],pos[N+5],L[N+5];
int rmq[N+5][20];
int n,m;
void buildSuffix(){
    memset(cnt,0,sizeof(int)*alphabet);
    for(int i=0;i<n;++i)++cnt[ s[i] ];
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

void buildLCP(){
    for(int i=0,k=0;i<n;++i)
        if(c[i]>0){
            int j=p[ c[i]-1 ];
            while(s[i+k]==s[j+k])++k;
            lcp[ c[i]-1 ]=k;
            if(k>0)--k;
            }
    lcp[n-1]=0;
    }

void buildRMQ(){
    for(int i=0;i<n;++i)rmq[i][0]=lcp[i];
    for(int k=1;(1<<k)<=n;++k)
        for(int i=0;i+(1<<k)-1<n;++i)rmq[i][k]=min(rmq[i][k-1],rmq[i+(1<<(k-1))][k-1]);
    }

int log2(int n){
    int ans=0;
    while((1<<ans)<=n)++ans;
    return ans-1;
    }
    
int getLCP(int x,int y){
    if(x==y)return n-c[x];
    if(x>y)swap(x,y);
    int k=log2(y-x);
    return min(rmq[x][k],rmq[y-(1<<k)][k]);
    }
char cad[105];
int main(){
    scanf("%d",&m);
    n=0;
    for(int i=0;i<m;++i){
        scanf("%s",cad);
        for(int j=0;cad[j];++j)pos[n]=i,L[n]=j+1,s[n++]=cad[j]-'a'+m;
        s[n++]=i;
        }    
    buildSuffix();
    buildLCP();
    buildRMQ();
    for(int i=0;i<m;++i)ans[i]=105;
    int str=0;
    for(int i=0,j=0;i<n && j<n;++i){
        while(str<2 && j<n)if(cnt[pos[p[j++]]]++==0)++str;
        while(str==2)if(--cnt[pos[p[i++]]])--str;                
        }
    }
