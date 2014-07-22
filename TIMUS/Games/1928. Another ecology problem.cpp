#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000
#define oo 1<<30
pair<int,int> dp[N+5][2];
int n,m,k;
pair<int,int> f(int n,bool player){
    if(n==0)return make_pair(0,0);
    pair<int,int> &ret=dp[n][player];
    if(ret.first!=-1 && ret.second!=-1)return ret;
    if(player)ret=make_pair(oo,-1);
    else make_pair(-1,oo);
    for(int i=1;i<=k;++i){
        pair<int,int> aux;
        if(i<=n)aux=f(n-i,player^1);
        else if(player)aux=make_pair(0,m-i);
        else aux=make_pair(m-i,0);
        if(player){
            if(i+aux.second==ret.second)ret.first=min(ret.first,aux.first);
            if(i+aux.second>ret.second)ret=make_pair(aux.first,i+aux.second);
            }
        else{
            if(i+aux.first==ret.first)ret.second=min(ret.second,aux.second);
            if(i+aux.first>ret.first)ret=make_pair(i+aux.first,aux.second);
            }
        }
    return ret;
    }
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=n;++i)
        for(int j=0;j<2;++j)dp[i][j]=make_pair(-1,-1);
    pair<int,int> ans=f(n,0);
    printf("%d %d\n",ans.first,ans.second);
    }
