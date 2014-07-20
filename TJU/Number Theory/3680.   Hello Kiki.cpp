#include<cstdio>
#include<algorithm>
using namespace std;
#define N 6
int C,n,caso;
long long m[N+5],r[N+5];
pair<long long,long long> gcd(long long a,long long b){
    if(b==0)return make_pair(1,0);
    pair<long long, long long> aux = gcd(b,a%b);
    return make_pair(aux.second,aux.first-(a/b)*aux.second);
    }

long long modInv(long long a,long long m){
    pair<long long,long long> aux=gcd(a,m);
    return (aux.first%m+m)%m;
    }

bool check(){
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j){
            long long d=__gcd(m[i],m[j]);
            if((r[i]%d)!=(r[j]%d))return false;
            }
    return true;
    }
    
long long chinese_remainder(){
    if(!check())return -1;
    long long mod=m[0];
    long long rem=r[0];
    for(int i=1;i<n;++i){
        long long d=__gcd(mod,m[i]);
        long long a=modInv(mod/d,m[i]/d);
        long long b=modInv(m[i]/d,mod/d);
        rem=((m[i]/d*b)*(rem/d)+(mod/d*a)*(r[i]/d));
        rem%=((mod/d)*(m[i]/d));
        mod/=d;
        mod*=(m[i]/d);
        rem%=mod;
        }
    
    for(int i=0;i<n;++i)if(rem<m[i])rem=rem+mod;
    return rem;
    }

void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%lld",m+i);
    for(int i=0;i<n;++i)scanf("%lld",r+i);
    long long ans=chinese_remainder();
    printf("Case %d: %lld\n",++caso,ans);
    }
int main(){
    caso=0;
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
