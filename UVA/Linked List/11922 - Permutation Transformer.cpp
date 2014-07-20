#include<cstdio>
#include<algorithm>
using namespace std;
#define sqN 4

int left[sqN],right[sqN],cnt[sqN];
int A[sqN][sqN];
bool rev[sqN];
int n,m,a,b;

inline void Reverse(int a,int b){
    int start=a/sqN;
    int end=b/sqN;
    for(int i=start+1;i<=end-1;++i)swap(left[i],right[i]),rev[i]^=1;
    if(rev[start])reverse(A[start],A[start]+cnt[start]),rev[start]^=1;
    if(rev[end])reverse(A[end],A[end]+cnt[end]),rev[end]^=1;
    reverse(A[start]+a%sqN,A[start]+cnt[start]);
    reverse(A[end],A[end]+b%sqN);
    }
    
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    
    for(int i=0,j=0;i<n;++i,++cnt[j]){
        if(cnt[j]==sqN)++j;
        A[j][cnt[j]]=i;
        }
    
    for(int i=0;i<sqN;++i){
        for(int j=0;j<cnt[i];++j)printf("%d ",A[i][j]+1);
        printf("\n");
        }
    
    for(int i=0;i<sqN;++i)left[i]=i-1,right[i]=i+1;
    
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        Reverse(--a,--b);
        }
        
    for(int i=0;i<sqN;++i)if(rev[i])reverse(A[i],A[i]+cnt[i]);
    int start=0;
    for(int i=0;i<sqN;++i)if(left[i]==-1)start=i;
    for(int i=0;i<sqN;++i,start=right[start])
        for(int j=0;j<cnt[start];++j)printf("%d\n",A[start][j]+1);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
