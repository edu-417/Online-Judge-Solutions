#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define N 1500
#define L 15
#define K 5381
#define hash unsigned long long
char c1[N+5][L+5],c2[N+5][L+5];
hash pow[L+5];
map<hash,bool> M;
int n,m,C,caso=0;
void doit(){
    M.clear();
    scanf("%d%d",&n,&m);
    gets(c1[0]);
    for(int i=0;i<n;++i)gets(c1[i]);
    for(int i=0;i<m;++i)gets(c2[i]);
    hash codeHash1,codeHash2,codeHash;
    for(int i=0;i<n;++i){
        codeHash1=K;
        for(int j=0;c1[i][j];++j)codeHash1=(codeHash1<<5)+codeHash1+c1[i][j]-'a';
        for(int j=0;j<m;++j){
            codeHash2=K;
            for(int k=0;c2[j][k];++k)codeHash2=(codeHash2<<5)+codeHash2+c2[j][k]-'a';
            codeHash=codeHash1*pow[strlen(c2[j])]+codeHash2-K*pow[strlen(c2[j])];
            M[codeHash]=true;
            }
        }
    printf("Case %d: %d\n",++caso,M.size());
    }
int main(){
    pow[0]=1;
    for(int i=1;i<=L;++i)pow[i]=(pow[i-1]<<5)+pow[i-1];
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
