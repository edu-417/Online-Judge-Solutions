#include<cstdio>

char c[15][15];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int n,m;
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
    }
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",c[i]);
    int ans=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(c[i][j]=='W')
                for(int k=0;k<4;++k){
                    int u=i+dx[k],v=j+dy[k];
                    if(!isValid(u,v))continue;
                    if(c[u][v]=='P'){
                        ++ans;
                        break;
                        }
                    }
    printf("%d\n",ans);
    }
