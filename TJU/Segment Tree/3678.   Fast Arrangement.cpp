#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 1000000

int a,b,k,q,C;
int tree[4*N+5];

void update(int node,int l,int r,int left,int right){
    int m=l+((r-l)>>1);
    update(Left(node),l,m,,);
    update(Right(node),m+1,r,,)
    
    }
bool f(int a,int b){
    return true;
    }
void doit(){
    scanf("%d%d",&k,&q);
    vector<int> v;
    for(int i=0;i<q;++i){
        scanf("%d%d",&a,&b);
        if(f(a,b))v.push_back(i+1);
        }
    for(int i=0;i<v.size();++i)printf("%s%d",i==0?"":" ",v[i]);
    printf("\n");
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
