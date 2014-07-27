#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define M 100000
int a[M+5];
int n,m;

int turn(int start,int end){
    return (end+n-start)%n;
    }
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    for(int i=0;i<m;++i)scanf("%d",a+i),--a[i];
    long long ans=0;
    int last=0;
    for(int i=0;i<m;++i)ans=ans+turn(last,a[i]),last=a[i];
    printf("%I64d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
