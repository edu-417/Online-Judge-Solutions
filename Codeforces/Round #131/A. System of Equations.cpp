#include<cstdio>
int n,m;
void doit(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i*i<=n;++i){
        int b=n-i*i;
        if(i+b*b==m)++ans;
        }
    printf("%d\n",ans);
    }
int main(){
    doit();
    }
