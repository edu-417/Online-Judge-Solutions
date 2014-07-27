#include<cstdio>
#include<algorithm>
using namespace std;

int a[200005],b[200005];
int n;
bool doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b,b+n);
    int ct=0;
    for(int i=0;i<n;++i)if(a[i]!=b[i])ct++;
    if(ct==0 || ct==2)printf("YES\n");
    else printf("NO\n");
    }
int main(){
    while(1)if(!doit())break;
    }
