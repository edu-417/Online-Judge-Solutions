#include<cstdio>
#include<cstring>
#define N 105
#define max(a,b) (a)>(b)? (a):(b)
int a[N][N],fila[N][N];
int n;
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",a[i]+j);
    for(int i=0;i<n;++i)memset(fila[i],0,sizeof(int)*n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)fila[i][j+1]=fila[i][j]+a[i][j];

    int ans=-(1<<30);
    for(int i=0;i<n;++i)
        for(int j=i;j<n;++j){
            int mayor=fila[0][j+1]-fila[0][i];
            int sum=0;
            for(int k=0;k<n;++k){
                mayor=max(mayor,fila[k][j+1]-fila[k][i]);
                if(sum+fila[k][j+1]-fila[k][i]<0){
                    sum=0;
                    continue;
                    }
                sum+=fila[k][j+1]-fila[k][i];
                mayor=max(mayor,sum);
                }
            ans=max(ans,mayor);
            }
    printf("%d\n",ans);
    return true;
    }

int main(){
    while(1)if(!doit())break;
        }
