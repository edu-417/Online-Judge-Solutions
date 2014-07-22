#include<cstdio>
#include<cstring>
#define SIZE 2
int n,m,x,y,MOD,C;

struct Matrix
{
	int X[SIZE][SIZE];
	
	Matrix () {}
	Matrix (int k)
	{
		memset(X, 0, sizeof(X));
		
		for(int i=0; i<SIZE; i++)
			X[i][i] = k;
	}
};

inline Matrix operator *(Matrix &A, Matrix &B)
{
	Matrix M;
	
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			int tmp = 0;
			for(int k=0; k<SIZE; k++)
				tmp = ((long long)A.X[i][k] * B.X[k][j]+tmp)%MOD;
			M.X[i][j] = tmp ;
		}
	}
	
	return M;
}

inline Matrix pow(Matrix x, long long n)
{
	Matrix P(1);
	
	while(n)
	{
		if(n & 1) P = P * x;
		
		n >>= 1;
		x = x * x;
	}
	
	return P;
}

inline Matrix build_matrix(){
    Matrix aux(0);
    aux.X[0][0]=3, aux.X[0][1]=2;
    aux.X[1][0]=1, aux.X[1][1]=1;
    return aux;
    }
inline int f(int n){
    if(n&1)return 0;
    if(n==0)return (1%MOD);
    Matrix aux=build_matrix();
    aux=pow(aux,(n-2)/2);
    int ans=((long long)aux.X[0][0]*3+aux.X[0][1])%MOD;
    return ans;        
    }

inline int g(int n){
    if(!(n&1))return 0;
    Matrix aux=build_matrix();
    aux=pow(aux,(n-1)/2);
    int ans=((long long)aux.X[1][0]*3+aux.X[1][1])%MOD;
    return ans;
    }

inline int h(){
    if(!(n&1))return 0;
    if(n==1 && !(m&1))return 0;
    if(n==1 && !(y&1))return 0;
    if(n==1)return (1%MOD);
    if(x==2){
        if(y==1 || y==m)return 0;
        int fy2=f(y-2),fmy1=f(m-y-1);
        int ans=((long long)2*fy2*fmy1)%MOD;
        if(y<m-1)ans=( (long long)2*fy2*g(m-y-2) +ans)%MOD;
        if(y>2)ans= ( (long long)2*g(y-3)*fmy1 +ans)%MOD;
        if(y>2 && y<m-1)ans=((long long)2*g(y-3)*g(m-y-2)+ans)%MOD;
        return ans;
        }
    int fy1=f(y-1),fmy=f(m-y);
    int ans= ((long long)fy1*fmy)%MOD;
    if(y<m)ans=( (long long)fy1*g(m-y-1) +ans )%MOD;
    if(y>1)ans=( (long long)g(y-2)*fmy +ans)%MOD;
    return ans;
    }
void doit(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&x,&y);
    scanf("%d",&MOD);
    int ans=h();
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }

