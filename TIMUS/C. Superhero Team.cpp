#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 1000
vector<int> L[N+5];
int x,mayor,n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&x),L[x].push_back(i),mayor=max(mayor,x);
    int s=0,tot=0,ant=0;
    for(int i=1;i<=mayor;++i){
        if(L[i].size()==0)continue;
        if(s>0 && s+1<i && ant<=s)++tot;
        s+=L[i].size();
        ant=i;
        }
    if(s>0 && ant<=s)++tot;
    s=0,ant=0;
    vector<int> ans;
    printf("%d\n",tot);
    for(int i=1;i<=mayor;++i){
        if(L[i].size()==0)continue;
        if(s>0 && s+1<i && ant<=s){
            printf("%d",s);
            for(int j=0;j<ans.size();++j)printf(" %d",ans[j]+1);
            printf("\n");
            }
        s+=L[i].size();
        for(int j=0;j<L[i].size();++j)ans.push_back(L[i][j]);
        ant=i;
        }
    if(s>0 && ant<=s){
        printf("%d",s);
        for(int j=0;j<ans.size();++j)printf(" %d",ans[j]+1);
        printf("\n");
        }
    }
