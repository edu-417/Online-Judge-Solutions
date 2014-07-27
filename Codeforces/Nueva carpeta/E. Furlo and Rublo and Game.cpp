#include<cstdio>
#include<cmath>
#include<set>
#include<iostream>
#include<map>
long long l;
int n;
using namespace std;
map<long long,int> M;
int grundy(long long x){
    if(M.find(x)!=M.end())return M[x];
    set<int> S;
    for(long long i=(long long)sqrt(sqrt(x));i<=(long long)sqrt(x) && i<x;++i)S.insert(grundy(i));
    int ans=0;
    while(S.count(ans))++ans;
    return M[x]=ans;
    }
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;++i){
        cin>>l;
        ans^=grundy(l);
        }
    if(ans==0)printf("Rublo\n");
    else printf("Furlo\n");
    }
