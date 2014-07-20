#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int t,w,n,caso=0;
int d[35],a[35], dp[1005];
int parent[35][1005];
bool doit(){
    if(scanf("%d%d",&t,&w)!=2)return false;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",d+i,a+i),d[i]*=3*w;
    memset(dp,0,sizeof(int)*(t+1));
    for(int i=0;i<n;++i)
        for(int j=0;j<=t;++j)parent[i][j]=j;
    for(int i=0;i<n;++i)
        for(int j=t;j>=d[i];--j)
            if(dp[j-d[i]]+a[i]>dp[j])
                dp[j]= dp[j-d[i]]+a[i],parent[i][j]=j-d[i];
    if(caso++>0)printf("\n");
    printf("%d\n",dp[t]);
    vector<int> path;
    for(int u=t,i=n-1;i>=0;u=parent[i][u],--i)
        if(u!=parent[i][u])path.push_back(i);
    printf("%d\n",path.size());
    for(size_t i=path.size()-1;i>0;--i)printf("%d %d\n",d[path[i]]/(3*w),a[path[i]]);
    if(path.size()>0)printf("%d %d\n",d[path[0]]/(3*w),a[path[0]]);
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
