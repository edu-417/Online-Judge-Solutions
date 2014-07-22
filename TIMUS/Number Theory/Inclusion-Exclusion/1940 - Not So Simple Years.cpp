#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define K 300
bool prime[K+5];
int primo[K+5];
int cnt,k,a,b;
long long ans;
void criba(){
    memset(prime,true,sizeof(bool)*(k+2));
    prime[0]=prime[1]=false;
    cnt=0;
    for(int i=2;i<=(k+1);++i)
        if(prime[i]){
            primo[cnt++]=i;
            for(int j=i*i;j<=(k+1);j+=i)prime[j]=false;
            }
    }
void back(int pos,int val,bool even,int x){
    if(pos==cnt){
        if(even)ans+=(x/val);
        else ans-=(x/val);
        return;
        }
    if((long long)val*primo[pos]>x){
        if(even)ans+=(x/val);
        else ans-=(x/val);
        return;
        }
    back(pos+1,val,even,x);
    back(pos+1,val*primo[pos],even^1,x);
    }

int f(int x){
    ans=0;
    back(0,1,true,x);
    return ans;
    }
    
int main(){
    scanf("%d%d%d",&a,&b,&k);
    criba();
    int ans=f(a+b)-f(a);
    for(int i=0;i<cnt;++i)if(primo[i]>a && primo[i]<=(a+b))++ans;
    printf("%d\n",ans);
    }
