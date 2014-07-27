#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char c[30];
string s[30005];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",c),s[i]=string(c);
    int m=s[0].length();
    sort(s,s+n);
    int ans=m;
    for(int i=1;i<n;++i)
        for(int j=0;j<m;++j)if(s[i][j]!=s[i-1][j])ans=min(ans,j);
    printf("%d\n",ans);
    }
