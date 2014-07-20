#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define hash unsigned int
#define L 15
#define N 120000
#define C 5381
map<hash,bool> M;
hash H[N+5],pow[L+5];
char c[N+5][L+5];
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
        M[ H[i] ]=true;
        }
        
    for(int i=0;i<n;++i){
        m=strlen(c[i]);
        hash codeHash=C;
        for(int j=0;j<m-1;++j){
            codeHash=(codeHash<<5)+codeHash+c[i][j]-'a';
            if(M[ codeHash ] && M[ H[i]- codeHash*pow[m-1-j] + C*pow[m-1-j] ]){
                printf("%s\n",c[i]);
                break;
                }
            }
        }
    }
