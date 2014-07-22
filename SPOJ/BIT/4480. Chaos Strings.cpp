#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 100000
int n,C;
string s[N+5];
char c[15];
int ind[N+5];
int tree[N+5],a[N+5];
void update(int idx){
    for(;idx<=n;idx+=(idx&-idx))++tree[idx];
    }
int query(int idx){
    int ans=0;
    for(;idx>0;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
    }

bool cmp(int x,int y){
    int n=s[x].length();
    int m=s[y].length();
    for(int i=0;i<n && i<m;++i)if(s[x][n-1-i]!=s[y][m-1-i])return s[x][n-1-i] < s[y][m-1-i];
    return n<m;
	}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%s",c),s[i]=string(c);
	sort(s,s+n);
	for(int i=0;i<n;++i)ind[i]=i;
	sort(ind,ind+n,cmp);
	long long ans=0;
	for(int i=n-1;i>=0;--i)ans+=query(ind[i]+1),update(ind[i]+1);
	printf("%lld\n",ans);
	}
