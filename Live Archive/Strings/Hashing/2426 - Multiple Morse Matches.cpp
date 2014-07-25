#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
#define hash unsigned int
#define L 1000
#define M 20
#define N 10000
char code[L+5];
char c[N+5][M+5];
int len[256],lenC[N+5];
hash hashMorse[256],hashCode[N+5],pow[L+5],codeHash[L+5];
int n,C,caso=0;
int dp[L+5];
string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
inline void doit(){
    scanf("%s",code);
    codeHash[0]=code[0]-'-'+1;
    for(int i=1;code[i];++i)codeHash[i]=(codeHash[i-1]<<1)+codeHash[i-1]+code[i]-'-'+1;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",c[i]);
    for(int i=0;i<n;++i){
        hashCode[i]=hashMorse[c[i][0]];
        lenC[i]=len[ c[i][0] ];
        for(int j=1;c[i][j];++j)
            hashCode[i]=hashCode[i]*pow[ len[ c[i][j] ] ] + hashMorse[ c[i][j] ],
            lenC[i]+=len[ c[i][j] ];
        }
    int m=strlen(code);
    memset(dp,0,sizeof(int)*m);
    dp[m]=1;
    for(int i=m-1;i>=0;--i){
        for(int j=0;j<n;++j){
            if(i+lenC[j]<=m){
                hash aux=codeHash[i+lenC[j]-1];
                if(i>0)aux=aux-codeHash[i-1]*pow[ lenC[j] ];
                if(hashCode[j]==aux)dp[i]+=dp[ i+lenC[j] ];
                }
            }
        }
    if(caso>0)cout<<endl;
    ++caso;
    cout<<dp[0]<<endl;
    //printf("%d\n",dp[0]);
    }
int main(){
    for(int i='A',j=0;i<='Z';++i,++j){
        len[i]=morse[j].length();
        hashMorse[i]=0;
        for(int k=0;k<len[i];++k)hashMorse[i]=(hashMorse[i]<<1)+hashMorse[i]+morse[j][k]-'-'+1;
        }
    pow[0]=1;
    for(int i=1;i<=M;++i)pow[i]=(pow[i-1]<<1)+pow[i-1];
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
