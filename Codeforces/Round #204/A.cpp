#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[10];
int n,x;
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    cnt[0]=cnt[5]=0;
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        cnt[x]++;
        }
    if(cnt[0]==0)printf("-1\n");
    else{
        cnt[5]/=9;cnt[5]*=9;
        bool zero=true;
        for(int i=0;i<cnt[5];++i)printf("5"),zero=false;
        if(zero)printf("0\n");
        else{
            for(int i=0;i<cnt[0];++i)printf("0");
            printf("\n");
            }
        }
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
