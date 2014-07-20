#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef unsigned int hash;
#define L 15
#define N 120000
#define MOD 1000000
#define C 5381
hash H[N+5],pow[L+5];
char c[N+5][L+5];
vector< hash> M[MOD];
int n,m;
int main(){
    n=0;
    pow[0]=1;
    for(int i=1;i<=L;++i)pow[i]=(pow[i-1]<<5)+pow[i-1];
    while(1){
        if(scanf("%s",c[n])!=1)break;
        ++n;
        }
    for(int i=0;i<n;++i){
        H[i]=(C<<5)+C+c[i][0]-'a';
        for(m=1;c[i][m];++m)H[i]=(H[i]<<5)+H[i]+c[i][m]-'a';
        hash pos=H[i]%MOD;
        M[pos].push_back(H[i]);
        }

    for(int i=0;i<n;++i){
        m=strlen(c[i]);
        hash codeHash=C;
        for(int j=0;j<m-1;++j){
            codeHash=(codeHash<<5)+codeHash+c[i][j]-'a';
            hash pos=codeHash%MOD;
            bool in1=false;
            for(int k=0;k<M[pos].size();++k)
                if(M[pos][k]==codeHash){in1=true;break;}
            if(!in1)continue;
            bool in2=false;
            hash codeHash2= H[i]- codeHash*pow[m-1-j] + C*pow[m-1-j];
            pos=codeHash2%MOD;
            for(int k=0;k<M[pos].size();++k)
                if(M[pos][k]==codeHash2){in2=true;break;}
            if(!in2)continue;
            printf("%s\n",c[i]);
            break;
            }
        }
    }
