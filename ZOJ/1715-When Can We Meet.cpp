#include<cstdio>
#include<cstring>
int c[105];
int n,q,m,x;
bool doit(){
    scanf("%d%d",&n,&q);
    if(n==0 && q==0)return false;
    memset(c,0,sizeof(c));
    for(int i=0;i<n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j)
            scanf("%d",&x),++c[x];
        }
    int ans=0;
    for(int i=1;i<=100;++i)if(c[i]>=q){
        if(c[i]>c[ans])ans=i;
        }
    printf("%d\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
