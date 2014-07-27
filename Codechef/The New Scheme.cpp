#include<cstdio>
#include<cstring>
#define MOD 1000000007
#define SIZE 2

int n,C;
struct Matrix{
    int X[SIZE][SIZE];
    Matrix(){}
    Matrix(int k){
        memset(X,0,sizeof(X));
        for(int i=0;i<SIZE;i++)X[i][i]= k;
    }
};

Matrix operator *(Matrix &A, Matrix &B){
    Matrix M;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            long long tmp=0;
            for(int k=0;k<SIZE;k++)tmp+=(long long)A.X[i][k]*B.X[k][j];
            M.X[i][j]=tmp%MOD;
        }
    }
    return M;
}

Matrix pow(Matrix x, long long n){
    Matrix P(1);
    while(n){
        if(n&1)P=P*x;
        n>>= 1;
        x=x*x;
    }
    return P;
}

void doit(){
    Matrix M(0);
    M.X[0][0]=2,M.X[0][1]=3;
    M.X[1][0]=1,M.X[1][1]=0;
    scanf("%d",&n);
    M=pow(M,n-1);
    int ans=(4LL*M.X[0][1])%MOD;
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
