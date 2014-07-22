#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define N 100000
int tree[4*N+5],cnt[N+5];
map<int,int> M;
char s[10];
int n,m,x;
void update(int node,int left,int right,const int &pos,const int &value){
    if(left==right)tree[node]=value;
    else{
        int m= left+((right-left)>>1);
        if(pos<=m)update(node<<1,left,m,pos,value);
        else update((node<<1)^1,m+1,right,pos,value);
        tree[node]=__gcd(tree[node<<1],tree[(node<<1)^1]);
        }    
    }
    
void doit(){
    scanf("%s%d",s,&x);
    if(s[0]=='+'){
        if(M.find(x)==M.end()){
            update(1,0,m-1,n,x);
            cnt[M[x]=n++]=1;
            }
        else if(cnt[M[x]]==0)update(1,0,m-1,M[x],x),++cnt[M[x]];
        else ++cnt[M[x]];
        }
    else if(--cnt[M[x]]==0)update(1,0,m-1,M[x],0);    
    printf("%d\n",tree[1]?tree[1]:1);
    }
    
int main(){
    n=0;
    scanf("%d",&m);
    for(int i=0;i<m;++i)doit();
    }
