#include<cstdio>
#include<cstring>
#define SIZE 3
#define MOD 1000000007
long long n;
int C;
struct matrix{
    int X[SIZE][SIZE];
    matrix(){
        }
    matrix(int k){
        memset(X,0,sizeof(X));
        for(int i=0;i<SIZE;++i)X[i][i]=k;
        }        
    };

matrix operator *(const matrix &A,const matrix &B){    
    matrix ans;
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j){
            long long aux=0;        
            for(int k=0;k<SIZE;++k)aux+=(long long)A.X[i][k]*B.X[k][j];
            ans.X[i][j]=aux%MOD;
        }
    return ans;
    }
    
matrix operator ^(matrix &A,long long n){    
    matrix ans(1);
    while(n>0){
        if(n&1)ans=ans*A;
        n>>=1;
        A=A*A;
        }
    return ans;    
    }
    
void doit(){
    scanf("%lld",&n);
    matrix aux(0);
    aux.X[0][0]=1,aux.X[0][1]=1;
    aux.X[1][1]=5,aux.X[1][2]=3;
    aux.X[2][1]=3,aux.X[2][2]=2;
    aux=aux^n;
    int ans=aux.X[0][1]<<1;
    if(ans>MOD)ans-=MOD;
    ans+=aux.X[0][2];
    if(ans>MOD)ans-=MOD;
    printf("%d\n",ans);
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
