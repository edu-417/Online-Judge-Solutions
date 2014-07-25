#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 10
#define K 100
int r,c,d;
bool first;

struct fr{
    long double x,y;
    fr(){}
    fr(long double _x,long double _y){
        x=_x,y=_y;
        }
    };
    
fr operator -(fr f1, fr f2){
    long double x=f2.y*f1.x-f1.y*f2.x;
    long double y=f1.y*f2.y;
    return fr(x,y);
    }
    
fr operator +(fr f1, fr f2){
    long double x=f2.y*f1.x+f1.y*f2.x;
    long double y=f1.y*f2.y;
    return fr(x,y);
    }
    
fr operator *(fr f1, fr f2){
    return fr(f1.x*f2.x,f1.y*f2.y);
    }

fr operator /(fr f1, fr f2){
    swap(f2.x,f2.y);
    return f1*f2;
    }

bool operator >(fr f1,fr f2){
    return (f1-f2).x>0;
    }

fr abs(fr f){return fr(fabs(f.x),f.y);}
vector<fr> ans;
fr a[N+5][N+5];
fr coef[K+5][K+5];

int id(int x,int y){return c*x+y;}
void formEq(int x,int y){
	int idx=id(x,y);
	int cnt=0;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			if(abs(x-i)+abs(y-j)<=d)coef[idx][id(i,j)]=fr(1,1),++cnt;
	
	coef[idx][id(r,0)]=fr(cnt,1)*a[x][y];
}

void gauss(){
	int n=r*c;
	int m=r*c;
	
	vector<int> where(m,-1);
	for(int col=0,row=0;col<m && row<n;++col){
		int sel=row;
		
		for(int i=row;i<n;++i)
			if( abs(coef[i][col]) > abs(coef[sel][col]) )sel=i;
		if( coef[sel][col].x == 0 )continue;
		
		for(int i=col;i<=m;++i)swap(coef[sel][i],coef[row][i]);
		where[col]=row;
		
		for(int i=0;i<n;++i)
			if(i!=row){
				fr C=coef[i][col]/coef[row][col];
				for(int j=col;j<=m;++j)coef[i][j]=coef[i][j]-C*coef[row][j];
			}
		++row;
	}
	ans.assign(m,fr(0,1));
	for(int i=0;i<m;++i)
		if(where[i]!=-1)ans[i]=coef[where[i]][m]/coef[where[i]][i];
}

bool doit(){
	scanf("%d%d%d",&r,&c,&d);
	if(r==0 && c==0 && d==0)return false;
	double x;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j){
            scanf("%lf",&x);
            a[i][j]=fr((long long)(100.0*x),1);
            }
	
    for(int i=0;i<=r*c;++i)
        for(int j=0;j<=r*c;++j)coef[i][j]=fr(0,1);
	
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)formEq(i,j);

	
	gauss();
	if(first)first=false;
	else printf("\n");
	int cnt=0;
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j,++cnt)printf("%8.2lf",ans[cnt].x*0.01/ans[cnt].y);
		printf("\n");
	}
	return true;
}
int main(){
    first=true;
	while(1)if(!doit())break;
}
