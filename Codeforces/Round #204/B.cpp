#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100000
bool b[N+5];
int n,x;
vector<int> v[N+5];
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<=N;++i)v[i].clear();
    for(int i=0;i<n;++i)scanf("%d",&x),v[x].push_back(i);
    int ans=0;
    for(int i=1;i<=N;++i){
        b[i]=true;
        if(v[i].size()==0)b[i]=false;
        else if(v[i].size()<2)++ans;
        else{
            int dif=v[i][1]-v[i][0];
            for(int j=2;j<v[i].size();++j)if(v[i][j]-v[i][j-1]!=dif)b[i]=false;
            if(b[i])++ans;
            }
        }
    printf("%d\n",ans);
    for(int i=1;i<=N;++i)
        if(b[i]){
            if(v[i].size()==1)printf("%d 0\n",i);
            else printf("%d %d\n",i,v[i][1]-v[i][0]);
            }            
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
