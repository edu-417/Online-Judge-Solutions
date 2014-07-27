#include<cstdio>
#include<algorithm>
using namespace std;
bool b[105][10005];
bool a[105],aux[105];
int pos[105],pos2[105];
int m,n;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)scanf("%1d",b[i]+j);
    int ans;
    for(int i=0;i<n;++i){
        bool val=false;
        for(int j=0;j<m;++j)if(b[i][j]){
            if(!val)pos[i]=j,val=true;
            pos2[i]=j;
            }
        if(!val)ans=-1;
        }
    int menor,mayor;
    menor=pos[0];
    mayor=pos2[0];
    for(int i=1;i<n;++i)menor=min(menor,pos[i]);
    for(int i=1;i<n;++i)mayor=max(mayor,pos2[i]);
    int s=0;
    for(int i=0;i<n;++i){
        int d1=min(pos[i]-menor,m-pos2[i]+menor);
        s+=d1;
        }
    if(ans!=-1)ans=s;
    s=0;
    for(int i=0;i<n;++i){
        int d2=min(mayor-pos2[i],pos[i]+m-mayor);
        s+=d2;
        }
    if(ans!=-1)ans=min(ans,s);
    printf("%d\n",ans);
    }
