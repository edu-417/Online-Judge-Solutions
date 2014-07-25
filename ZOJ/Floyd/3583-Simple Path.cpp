#include<cstdio>
#include<cstring>
#define N 105
bool d[N][N];
int n,m,source,sink,x,y;
bool doit(){
    if(scanf("%d%d",&n,&m)!=2)return false;
    scanf("%d%d",&source,&sink);
    for(int i=0;i<n;++i)memset(d[i],false,sizeof(bool)*n);
    for(int i=0;i<n;++i)d[i][i]=true;
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),d[x][y]=d[y][x]=true;
    int ans=0;
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(i==source && j==sink && d[i][k] && d[k][j]){
                    ++ans;
                    printf("k: %d\n",k);
                    }
                d[i][j]|=(d[i][k]&&d[k][j]);
                }
        printf("%d : \n",k);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)printf("%1d ",d[i][j]);
            printf("\n");
            }
        printf("\n");
        }
    ans=n-ans;
    printf("%d\n\n\n",ans);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
