#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 4000
vector<int> a[4],b,c;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<4;++i)a[i].resize(n);
    for(int i=0;i<n;++i)
        for(int j=0;j<4;++j)scanf("%d",&a[j][i]);
    int m=n*n;
    b.resize(m);    c.resize(m);
    for(int i=0,cnt=0;i<n;++i)
        for(int j=0;j<n;++j,++cnt)b[cnt]=a[0][i]+a[1][j];
    for(int i=0,cnt=0;i<n;++i)
        for(int j=0;j<n;++j,++cnt)c[cnt]=a[2][i]+a[3][j];
    sort(c.begin(),c.end());
    int ans=0;
    for(int i=0;i<m;++i){
        int lo=upper_bound(c.begin(),c.end(),-b[i])-c.begin();
        int hi=lower_bound(c.begin(),c.end(),-b[i])-c.begin();
        ans+=(lo-hi);
        }
    printf("%d\n",ans);
    }
    

