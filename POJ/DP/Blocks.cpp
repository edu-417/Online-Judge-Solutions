#include<cstdio>
#include<cstring>
#define SIZE 4
#define MOD 10007

int n,C;
struct matrix{
    int X[SIZE][SIZE];
    matrix(){}
    matrix(int k){
        memset(X,0,sizeof(X));
        for(int i=0;i<SIZE;++i)X[i][i]=k;
        }
    };

matrix operator *(const matrix &A, const matrix &B){
    matrix ans;
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j){
            int aux=0;
            for(int k=0;k<SIZE;++k)aux+=A.X[i][k]*B.X[k][j];
            ans.X[i][j]=aux%MOD;            
            }            
    return ans;
    }

matrix operator ^(matrix &A,int n){
    matrix ans(1);
    for(;n>0;n>>=1){
        if(n&1)ans=ans*A;
        A=A*A;
        }
    return ans;
    }
    
void doit(){
    scanf("%d",&n);
    matrix aux(2);
    aux.X[0][1]=aux.X[0][2]=1;
    aux.X[1][0]=aux.X[1][3]=1;
    aux.X[2][0]=aux.X[2][3]=1;
    aux.X[3][1]=aux.X[3][2]=1;
    aux=aux^n;
    int ans=aux.X[0][0];
    printf("%d\n",ans);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
