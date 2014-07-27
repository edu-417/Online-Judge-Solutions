#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[3];
int a[50];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)cnt[i%3]+=a[i];
    int mayor=max(cnt[0],max(cnt[1],cnt[2]));
    if(cnt[0]==mayor)printf("chest\n");
    else if(cnt[1]==mayor)printf("biceps\n");
    else printf("back\n");
    }
