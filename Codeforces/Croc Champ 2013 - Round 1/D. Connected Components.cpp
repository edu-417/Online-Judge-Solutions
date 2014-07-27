#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500
#define M 10000

int Ex[M+5],Ey[M+5];
int n,m,k,a,b;
struct data{
    vector< vector<int> > L;
    vector< int> p;
    int cc;
    data(){
        L.resize(n,vector<int>());
        p.resize(n);
        for(int i=0;i<n;++i)p[i]=i;
        cc=0;
        }
    int find(int x){
        if(x==p[x])return p[x];
        return p[x]=find(p[x]);
        }
    void Union(int x,int y){
        x=find(x);
        y=find(y);
        p[x]=y;
        }
    };


data make_data(int pos){
    data ans;
    ans.L[Ex[pos]].push_back(Ey[pos]);
    ans.L[Ey[pos]].push_back(Ex[pos]);
    ans.cc=n-1;
    return ans;
    }
data combine(data &l,data &r){
    data ans;
    for(int i=0;i<n;++i)merge(l.L[i].begin(), l.L[i].end(), r.L[i].begin(), r.L[i].end(), back_inserter(ans.L[i]) );
    for(int i=0;i<n;++i)
        for(int j=0;j<ans.L[i].size();++j)ans.Union(i,ans.L[i][j]);
    for(int i=0;i<n;++i)if(ans.p[i]==i)++ans.cc;
    return ans;
    }
    
data tree[4*M+5];
void build(int node,int l,int r){
    if(l==r)tree[node]=make_data(l);
    else{
        int m=l+((r-l)>>1);
        build(node<<1,l,m);
        build((node<<1)^1,m+1,r);
        tree[node]=combine(tree[node<<1],tree[(node<<1)^1]);
        }
    }

data query(int node,int l,int r,int left,int right){
    if(l==left && r==right)return tree[node];
    int m=l+((r-l)>>1);
    if(right<=m)return query(node<<1,l,m,left,right);
    if(left>m)return query((node<<1)^1,m+1,r,left,right);
    data L=query(node<<1,l,m,left,m);
    data R=query((node<<1)^1,m+1,r,m+1,right);
    return combine(L,R);
    }

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)scanf("%d%d",Ex+i,Ey+i),--Ex[i],--Ey[i];
    build(1,0,m-1);
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d%d",&a,&b);
        --a,--b;
        if(a==0 && b==m-1){
            printf("%d\n",n);
            continue;
            }
        if(a==0){
            data ans=query(1,0,m-1,b+1,m-1);
            printf("%d\n",ans.cc);
            continue;
            }
        if(b==m-1){
            data ans=query(1,0,m-1,0,a-1);
            printf("%d\n",ans.cc);
            continue;
            }
        data L=query(1,0,m-1,0,a-1);
        data R=query(1,0,m-1,b+1,m-1);
        data ans=combine(L,R);
        printf("%d\n",ans.cc);
        }
    }
