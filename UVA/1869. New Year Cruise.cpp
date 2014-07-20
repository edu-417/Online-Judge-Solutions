#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[200][200];
int t[200];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)scanf("%d",a[i]+j);
	for(int i=0;i<n;++i)t[0]+=a[0][i];
	int ans=t[0];
	for(int i=1;i<n-1;++i)
		for(int j=0;j<i;++j){
			t[i]+=a[j][i],t[j]-=a[j][i];
			ans=max(ans,t[i]);
			}
	for(int i=0;i<n;++i)t[i]=0;
	for(int i=0;i<n;++i)t[n-1]+=a[n-1][i];
	ans=max(ans,t[n-1]);
	for(int i=n-2;i>0;--i)
		for(int j=n-1;j>i;--j){
			t[i]+=a[j][i],t[j]-=a[j][i];
			ans=max(ans,t[i]);
			}
	if(ans==0)printf("0\n");
	else printf("%d\n",(ans-1)/36+1);
	}
