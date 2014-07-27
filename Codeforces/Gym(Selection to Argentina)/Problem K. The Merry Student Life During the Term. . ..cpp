#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 500
#define M 100
int n,g;
long long k[N+5],p[N+5][M+5],w[N+5][M+5];
int ind[N+5][M+5],ind2[N+5],K[N+5];
long long pen[N+5],wac[N+5],pac[N+5];
bool cmp(int x,int y){
    return w[g][y]*p[g][x]<w[g][x]*p[g][y];
    }

bool cmp2(int x,int y){
    return wac[y]*pac[x]<wac[x]*pac[y];
    }
int main(){
    freopen("student.in","r",stdin);
    freopen("student.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",k+i),K[i+1]=K[i]+k[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<k[i];++j)scanf("%d",p[i]+j),pac[i]+=p[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<k[i];++j)scanf("%d",w[i]+j),wac[i]+=w[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<k[i];++j)ind[i][j]=j;
    for(int i=0;i<n;++i){
        g=i;
        sort(ind[i],ind[i]+k[i],cmp);
        }
    long long ans=0;
    for(int i=0;i<n;++i)ind2[i]=i;
    sort(ind2,ind2+n,cmp2);
    long long ac=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<k[i];++j){
            ac+=p[ind2[i]][j];
            ans=ans+ ac*w[ind2[i]][j];
            }
        }
    cout<<ans<<"\n";
    int cnt=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<k[ind2[i]];++j)printf("%s%d",(i==0 && j==0)?"":" ",ind[ind2[i]][j]+1+K[i]);       
    printf("\n");
    }
