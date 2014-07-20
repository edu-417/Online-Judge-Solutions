#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
//a^x=b(mod m)
int n,p,b;
int discreteLog(int a,int b,int m){
    int n=(int)sqrt((double)m)+1;
    int an=1;
    for(int i=0;i<n;++i)an=(long long)an*a%m;    
    map<int,int> M;
    for(int i=1,aux=an;i<=n;++i)M[aux]=i,aux=(long long)aux*an%m;
    for(int i=0,aux=b;i<=n;++i)
        if(M.find(aux)!=M.end()){
            long long ans=(long long)M[aux]*n-i;
            if(ans<m)return (int)ans;
            }        
    return -1;
    }
    
bool doit(){
    scanf("%d%d%d",&p,&b,&n);
    int ans=discreteLog(n,b,p);
    if(ans==-1)printf("no solution\n");
    else printf("%d\n",ans);
    }
    
int main(){
    while(1)if(!doit())break;
    }
