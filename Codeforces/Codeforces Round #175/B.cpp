#include<cstdio>
#define N 100000
int p[N+5];
int n,s,e;
int main(){
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n;++i)scanf("%d",p+i);
    bool first=true;
    int ans=0;
    bool val=false;
    for(int i=s;;i=p[i]){
        if(!first && i==s)break;
        if(i==e){
            val=true;
            break;
            }
        ++ans;
        first=false;
        }
    printf("%d\n",val?ans:-1);
    
    }
