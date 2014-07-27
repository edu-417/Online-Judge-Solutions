#include<cstdio>

int n;
int x[500],y[500],p[500];
int Find(int x){
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
    }
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    p[y]=x;
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;++i)p[i]=i;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(x[i]==x[j] || y[i]==y[j])Union(i,j);
    int ans=0;
    for(int i=0;i<n;++i)if(p[i]==i)++ans;
    printf("%d\n",ans-1);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
