#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define N 100000
int n,k,x;
long long ip[N+5];
map<long long,bool> M;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            if(j>0)scanf("%*1s");
            scanf("%d",&x),ip[i]=(ip[i]<<8)^x;
            }
        }
    long long ans=-1;
    long long mask=0;
    for(int j=31;j>0;--j){
        M.clear();
        mask^=(1<<j);
        for(int i=0;i<n;++i){
            long long mask2=mask&ip[i];
            M[mask2]=true;
            }
        if(M.size()==k){
            ans=mask;
            break;
            }
        }
    if(ans==-1)printf("-1\n");
    else{
        int subMask[4];
        for(int i=3;i>=0;--i)subMask[i]=ans&255,ans>>=8;
        for(int i=0;i<4;++i)printf("%s%d",i==0?"":".",subMask[i]);
        printf("\n");
        }
    }
