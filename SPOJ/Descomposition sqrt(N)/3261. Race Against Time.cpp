#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
#define sqN 320
int n,q;
int ind[N+5],A[N+5];
bool cmp(int x,int y){
    return A[x]<A[y];
    }

void update(int idx,int x){
    int start=(idx/sqN)*sqN;
    A[idx]=x;
    sort(ind+start,ind+min(n,start+sqN),cmp);
    }

int bs(int a,int b,int x){
    int lo=a,hi=b-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(A[ind[mid]]>x)hi=mid;
        else lo=mid+1;
        }
    if(A[ind[lo]]<=x)return b-a;
    return lo-a;
    }
int query(int a,int b,int x){
    int start=(a/sqN)*sqN;
    int end=(b/sqN)*sqN;
    int ans=0;
    if(start!=end)for(int i=start;i<start+sqN && i<n;++i)if(ind[i]>=a && ind[i]<=b && A[ind[i]]<=x)++ans;
    for(int i=start+sqN;i<end && i<n;i+=sqN)ans+=bs(i,min(n,i+sqN),x);
    for(int i=end;i<end+sqN && i<n;++i)if(ind[i]>=a && ind[i]<=b && A[ind[i]]<=x)++ans;
    return ans;
    }
    
char s[2];
int main(){
    int idx,x,a,b;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)scanf("%d",A+i);
    for(int i=0;i<n;++i)ind[i]=i;
    for(int i=0;i<n;i+=sqN)sort(ind+i,ind+min(n,i+sqN),cmp);
    for(int i=0;i<q;++i){
        scanf("%s",s);
        if(s[0]=='M'){
            scanf("%d%d",&idx,&x);
            update(--idx,x);
            }
        else{
            scanf("%d%d%d",&a,&b,&x);
            printf("%d\n",query(--a,--b,x));
            }
        }
    }
