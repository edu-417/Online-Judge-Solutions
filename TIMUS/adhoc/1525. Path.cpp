#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
char dir[]="rludfb";
int M[256];
int dx[]={1,-1,1,-1,1,-1};
int desp[6];
int lim[6];
int n,m,p;
char s[N+5];
bool doit(){
    if(scanf("%d%d%d",&n,&m,&p)!=3)return false;
    scanf("%s",s);
    for(int i=0;i<6;++i)desp[i]=0;
    for(int i=0;i<6;++i)lim[i]=0;
    for(int i=0;s[i];++i){
        int idx=M[s[i]];
        desp[idx/2]+=dx[idx];
        if(idx&1)lim[idx]=min(lim[idx],desp[idx/2]);
        else lim[idx]=max(lim[idx],desp[idx/2]);
        }
    n-=lim[0],n+=lim[1];
    m-=lim[2],m+=lim[3];
    p-=lim[4],p+=lim[5];
    n=max(1,n);
    m=max(1,m);
    p=max(1,p);
    long long ans=(long long)n*m*p;
    printf("%I64d\n",ans);
    return true;
    }
int main(){
    for(int i=0;i<6;++i)M[dir[i]]=i;
    while(1)if(!doit())break;
    }
