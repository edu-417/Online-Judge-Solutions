#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
map<pair<int,int>,long long > M;
int n;
long long f(int mask1,int mask2){
    if(mask1==(1<<n)-1)return mask2==mask1;
    if(M.find(make_pair(mask1,mask2))!=M.end())return M[make_pair(mask1,mask2)];
    int pos=__builtin_popcount(mask1);
    long long ans=0;
    for(int i=0;i<n;++i){
        if( !( (mask1>>i)&1 )  &&  !( (mask2>>( (pos+i)%n ) )&1 ) )ans+=f(mask1^(1<<i),mask2^(1<<( (pos+i)%n) ));
        }
    return M[make_pair(mask1,mask2)]=ans;
    }
int main(){
    scanf("%d",&n);
    printf("%d\n",f(0,0));
    }
