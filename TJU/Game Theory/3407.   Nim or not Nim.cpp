#include<cstdio>
int n,C,x;

int grundy(int x){
	if(x==0)return 0;
	if(x%4==0)return x-1;
	if(x%4==3)return x+1;
	return x;	
	}
void doit(){
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;++i)scanf("%d",&x),ans^=grundy(x);
	printf("%s\n",ans==0?"Bob":"Alice");
	}
	
int main(){
	scanf("%d",&C);
	for(int i=0;i<C;++i)doit();
	}
