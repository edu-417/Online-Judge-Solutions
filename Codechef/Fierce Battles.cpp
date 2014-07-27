#include<cstdio>
int n,m,C,c,l;
int t[105];
void doit(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=100;++i)t[i]=0;
    for(int i=0;i<n;++i)scanf("%d%d",&c,&l),t[l]+=c;
    for(int i=0;i<m;++i)scanf("%d%d",&c,&l),t[l]-=c;
    int ans=0;
    for(int i=1;i<=100;++i)if(t[i]<0)ans-=t[i];
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
