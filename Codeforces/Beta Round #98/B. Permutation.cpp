#include<cstdio>

bool b[5005];
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(x<=n)b[x]=true;
        }
    int ans=0;
    for(int i=1;i<=n;++i)if(!b[i])++ans;
    printf("%d\n",ans);
    }
