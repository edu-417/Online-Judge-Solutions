#include<cstdio>
#include<cstring>
#define SIZE 40
#define MOD 10
struct matrix{
    int size;
    int X[SIZE][SIZE];
    matrix(){
        memset(X,0,sizeof(X));
        }
        
    matrix(int _size):size(_size){
        memset(X,0,sizeof(X));
        }
    
    int & operator()(int i,int j){
        return X[i][j];
        }
    
    void print(){
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j)printf("%d ",X[i][j]);
            printf("\n");
            }            
        }
    };

matrix identity(int size){
    matrix I(size);
    for(int i=0;i<size;++i)I(i,i)=1;
    return I;
    }
    
matrix operator +(matrix &A,matrix &B){
    matrix ans(A.size);
    for(int i=0;i<A.size;++i)
        for(int j=0;j<A.size;++j)ans(i,j)=(A(i,j)+B(i,j))%MOD;
    return ans;
    }

matrix operator *(matrix &A,matrix &B){
    matrix ans(A.size);
    for(int i=0;i<A.size;++i)
        for(int j=0;j<B.size;++j){
            int aux=0;
            for(int k=0;k<A.size;++k)aux+=A(i,k)*B(k,j);
            ans(i,j)=aux%MOD;
            }
    return ans;
    }

struct Matrix{
    int size;
    matrix X[4][4];
    Matrix(){
        size=4;
        for(int i=0;i<size;++i)
            for(int j=0;j<size;++j)X[i][j]=matrix();
        }
    
    matrix & operator()(int i,int j){
        return X[i][j];
        }
    
    void print(){
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)X[i][j].print();
        }
    };

Matrix Identity(int size){
    Matrix I;
    for(int i=0;i<4;++i)I(i,i)=identity(size);
    return I;
    }

Matrix operator +(Matrix &A,Matrix &B){
    Matrix ans;
    for(int i=0;i<A.size;++i)
        for(int j=0;j<A.size;++j)ans(i,j)=A(i,j)+B(i,j);
    return ans;
    }

Matrix operator *(Matrix &A,Matrix &B){
    Matrix ans;
    for(int i=0;i<A.size;++i)
        for(int j=0;j<B.size;++j){
            matrix aux;
            for(int k=0;k<A.size;++k){
                matrix aux2=A(i,k)*B(k,j);
                aux=aux+aux2;
                }
            ans(i,j)=aux;
            }
    return ans;
    }
Matrix operator ^(Matrix &A,int n){
    Matrix ans=Identity(A(0,0).size);
    while(n>0){
        if(n&1)ans=ans*A;
        A=A*A;
        n>>=1;
        }
    return ans;
    }
    
int n,k,x;
bool doit(){
    scanf("%d%d",&n,&k);
    if(n==0 && k==0)return false;
    matrix A(n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)scanf("%d",&x),A(i,j)=x%10;
    Matrix T;
    T(0,0)=identity(n);    T(0,1)=identity(n);
    T(1,0)=matrix();        T(1,1)=A;
    T=T^(k-1);
    matrix ans(n);
    ans=T(0,0)*A;
    A=A*A;
    matrix aux(n);
    aux=T(0,1)*A;
    ans=ans+aux;
    ans.print();
    return true;
    }
    
int main(){
    while(1)if(!doit())break;
    }
