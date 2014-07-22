#include<cstdio>
#include<cstring>
int n,m,x;
char c[1000000];
int main(){
    scanf("%d%d",&n,&m);
    bool b=false;
    for(int i=0;i<m;++i){
        scanf("%s",&c);
        if(strcmp(c,"1")==0)b=true;
        }
    int rest=n-m;
    if(b)--m;
    else --rest;
    int need=n/3-1;
    int ans=0;
    if(m>0 && m-2>=need)ans+=m*(m-1)/2;
    if(m-1>=need)ans+=m*rest;
    if(rest>0 && b)ans+=rest*(rest-1)/2;
    printf("%d\n",ans);
    }
