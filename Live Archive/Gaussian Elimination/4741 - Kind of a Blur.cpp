#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 10
#define K 100
#define eps 1e-4
double a[N+5][N+5];
long double coef[K+5][K+5];
int r,c,d;
bool first;
vector<double> ans;

int id(int x,int y){return c*x+y;}
void formEq(int x,int y){
	int idx=id(x,y);
	int cnt=0;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			if(abs(x-i)+abs(y-j)<=d)coef[idx][id(i,j)]=1,++cnt;
	
	coef[idx][id(r,0)]=cnt*a[x][y];
}

void gauss(){
	int n=r*c;
	int m=r*c;
	
	vector<int> where(m,-1);
	for(int col=0,row=0;col<m && row<n;++col){
		int sel=row;
		
		for(int i=row;i<n;++i)
			if( fabs(coef[i][col]) > fabs(coef[sel][col]) )sel=i;
		if( fabs( coef[sel][col] ) <eps )continue;
		
		for(int i=col;i<=m;++i)swap(coef[sel][i],coef[row][i]);
		where[col]=row;
		
		for(int i=0;i<n;++i)
			if(i!=row){
				long double C=coef[i][col]/coef[row][col];
				for(int j=col;j<=m;++j)coef[i][j]-=C*coef[row][j];
			}
		++row;
	}
	ans.assign(m,0);
	for(int i=0;i<m;++i)
		if(where[i]!=-1)ans[i]=coef[where[i]][m]/coef[where[i]][i];
}

bool doit(){
	scanf("%d%d%d",&r,&c,&d);
	if(r==0 && c==0 && d==0)return false;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)scanf("%lf",a[i]+j);
	
    memset(coef,0,sizeof(coef));
	
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)formEq(i,j);

	
	gauss();
	if(first)first=false;
	else printf("\n");
	int cnt=0;
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j,++cnt)printf("%8.2lf",ans[cnt]);
		printf("\n");
	}
	return true;
}
int main(){
    first=true;
	while(1)if(!doit())break;
}
