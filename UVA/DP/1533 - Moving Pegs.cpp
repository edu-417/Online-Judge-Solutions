#include<cstdio>
#include<algorithm>
using namespace std;
#define n 15
#define oo 1<<20
int a[12][10]={ {11,12,13,14,15},{7,8,9,10},{4,5,6},{2,3},{7,12},{4,8,13},
{2,5,9,14},{1,3,6,10,15},{1,2,4,7,11},{3,5,8,12},{6,9,13},{10,14}};

int L[12]={5,4,3,2,2,3,4,5,5,4,3,2};
int dp[(1<<n)+5];
int affect[n+5][n+5],d[n+5][n+5];
bool can[n+5][n+5];
bool used[(1<<n)+5],end[(1<<n)+5];
pair<int,int> move[(1<<n)+5];

int hole,C;

void printMask(int mask){
    for(int i=0;i<n;++i)if(((mask>>i)&1))printf("%d ",i+1);
    printf("\n");
    }

int getMask(int mask,int x,int y){
	mask^=(1<<x);
	mask^=(1<<y);
	return mask&affect[x][y];
	}

void rec(int mask){
    int l=dp[mask];
    for(int i=0;i<l;++i){
        printMask(mask);
        printf("move: %d-%d\n",move[mask].first+1,move[mask].second+1);
        mask=getMask(mask,move[mask].first,move[mask].second);
        }
	}
	
int f(int mask){
    printMask(mask);
	if(__builtin_popcount(mask)==1 && ( (mask>>hole)&1 ) )return 0;
	int &ret=dp[mask];
	if(end[mask])return ret;
	if(used[mask])return oo;
	used[mask]=true;
	int ans=oo;
	for(int i=0;i<n;++i)
		if( (mask>>i)&1 ){
            int dis=oo;
            for(int j=0;j<n;++j)
				if( !( (mask>>j)&1) && can[i][j] ){
                    if(d[i][j]==oo)continue;
                    if(d[i][j]<dis)dis=d[i][j];
					}
			if(dis==oo)continue;
			for(int j=0;j<n;++j)
				if( !( (mask>>j)&1) && can[i][j] && d[i][j]==dis){
                    int aux=1+f( getMask(mask,i,j) );
            		if(aux==ans){
            		  if(make_pair(i,j)<move[mask])move[mask]=make_pair(i,j);
            		  }
            		else if(aux<ans){
            		  ans=aux;
            		  move[mask]=make_pair(i,j);
            		  }
					}
            }
	end[mask]=true;
	return ret=ans;
	}

void doit(){
	scanf("%d",&hole);
	--hole;
	int mask=((1<<n)-1)^(1<<hole);
    int ans=f(mask);
	if(ans==oo)printf("IMPOSSIBLE\n");
	else{
        printf("%d\n",ans);
    	rec(mask);
        }
	}
int main(){
	
	for(int i=0;i<n;++i)
	   for(int j=0;j<n;++j)affect[i][j]=(1<<n)-1,can[i][j]=false,d[i][j]=oo;
	for(int i=0;i<12;++i){
        for(int j=0;j<L[i];++j){
            for(int k=j+1;k<L[i];++k){
				int mask=(1<<n)-1;
				for(int idx=j+1;idx<k;++idx)mask^=( 1<<(a[i][idx]-1) );
				affect[a[i][j]-1][a[i][k]-1]=mask;
				affect[a[i][k]-1][a[i][j]-1]=mask;
				can[a[i][j]-1][a[i][k]-1]=true;
				can[a[i][k]-1][a[i][j]-1]=true;
				d[a[i][j]-1][a[i][k]-1]=k-j;
				d[a[i][k]-1][a[i][j]-1]=k-j;
				}
            }
        }
    
	scanf("%d",&C);
	memset(used,false,sizeof(used));
	memset(end,false,sizeof(end));
	//for(int i=0;i<(1<<n);++i)f(i);
	for(int i=0;i<C;++i)doit();
	}
