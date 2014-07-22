#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,C;
unsigned long long dp[20][(1<<10)+5][(1<<5)+5][2][2];
bool used[20][(1<<10)+5][(1<<5)+5][2][2];
string s;
unsigned long long a,b;

string toString(unsigned long long x){
	if(x==0)return "0";
	string ans="";
	while(x>0){
		int d=x%10;
		x/=10;
		ans=char(d+'0')+ans;
		}
	return ans;
	}

bool valid(int mask,int mask2){
	for(int i=1;i<10;i+=2)if( ((mask>>i)&1) )return false;
	for(int i=0;i<10;i+=2){
		if( !( ( mask2>>(i/2) )&1 ) )continue;
		if(  !((mask>>i)&1) )return false;
		}
	return true;
	}
	
unsigned long long f(int pos,int mask,int mask2,bool equal,bool zero){
	if(pos==n){
		if(zero)return 1;
		return valid(mask,mask2);
		}
	unsigned long long &ret=dp[pos][mask][mask2][equal][zero];
	if(used[pos][mask][mask2][equal][zero])return ret;
	used[pos][mask][mask2][equal][zero]=true;
	int end=9;
	if(equal)end=s[pos]-'0';
	unsigned long long ans=0;
	for(int i=0;i<=end;i+=2)
		if(i>0 || (i==0 && !zero) )ans+=f(pos+1,mask^(1<<i),mask2|( 1<<(i/2)),equal&&(i==end),false);
		else ans+=f(pos+1,mask,mask2,equal&&(i==end),true);
	for(int i=1;i<=end;i+=2)ans+=f(pos+1,mask^(1<<i),mask2,equal&&(i==end),false);
	return ret=ans;
	}
	
unsigned long long g(unsigned long long x){
	s=toString(x);
	n=s.length();
	for(int i=0;i<n;++i)
	   for(int j=0;j<(1<<10);++j)
	       for(int k=0;k<(1<<5);++k)memset(used[i][j][k],false,sizeof(used[i][j][k]));
	return f(0,0,0,1,1);
	}
	
void doit(){
	scanf("%llu%llu",&a,&b);
	unsigned long long ans=g(b)-g(a-1);
	printf("%llu\n",ans);	
	}
	
int main(){
	scanf("%d",&C);
	for(int i=0;i<C;++i)doit();
	}

