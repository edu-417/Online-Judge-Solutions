#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int n,x;
map<int,int> M;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(x>0)++M[x];
        }
    bool val=true;
    int ans=0;
    for(map<int,int> ::iterator it=M.begin();it!=M.end();++it)
        if(it->second>2)val=false;
        else ans=ans+it->second/2;
    if(!val)ans=-1;
    printf("%d\n",ans);
    }
