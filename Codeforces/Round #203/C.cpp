#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100000
int n;
int x[N+5],y[N+5];
vector<int> L[N+5];
int ind[N+5];

int cuad(int a,int b){
    if(a==0)return 0;
    if(b==0)return 1;
    if(a<0 && b<0)return 2;
    if(a<0 && b>0)return 3;
    if(a>0 && b<0)return 4;
    return 5;
    }
bool cmp(int a,int b){
    if(cuad(x[a],y[a])!=cuad(x[b],y[b]))return cuad(x[a],y[a])<cuad(x[b],y[b]);
    if(x[a]==x[b])return abs(y[a])<abs(y[b]);
    return abs(x[a])<abs(x[b]);
    }
    
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;++i)ind[i]=i;
    sort(ind,ind+n,cmp);    
    int ans=0;
    for(int i=0;i<n;++i){
        if(x[i]!=0)ans+=2;
        if(y[i]!=0)ans+=2;
        ans+=2;
        }
        
    printf("%d\n",ans);
    for(int i=0;i<n;++i){
        if(x[ind[i]]<0 && y[ind[i]]<0){
            if(x[ind[i]]!=0)printf("1 %d L\n",-x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d D\n",-y[ind[i]]);
            printf("2\n");
            if(x[ind[i]]!=0)printf("1 %d R\n",-x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d U\n",-y[ind[i]]);
            printf("3\n");
            }
        else if(x[ind[i]]<0 && y[ind[i]]>=0){
            if(x[ind[i]]!=0)printf("1 %d L\n",-x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d U\n",y[ind[i]]);
            printf("2\n");
            if(x[ind[i]]!=0)printf("1 %d R\n",-x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d D\n",y[ind[i]]);
            printf("3\n");
            }
        else if(x[ind[i]]>=0 && y[ind[i]]<0){
            if(x[ind[i]]!=0)printf("1 %d R\n",x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d D\n",-y[ind[i]]);
            printf("2\n");
            if(x[ind[i]]!=0)printf("1 %d L\n",x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d U\n",-y[ind[i]]);
            printf("3\n");
            }
        else if(x[ind[i]]>=0 && y[ind[i]]>=0){
            if(x[ind[i]]!=0)printf("1 %d R\n",x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d U\n",y[ind[i]]);
            printf("2\n");
            if(x[ind[i]]!=0)printf("1 %d L\n",x[ind[i]]);
            if(y[ind[i]]!=0)printf("1 %d D\n",y[ind[i]]);
            printf("3\n");
            }
        }
    }
