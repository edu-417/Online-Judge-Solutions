#include<cstdio>
#include<string>
#include<cstring>
#include<assert.h>
using namespace std;
#define hash pair<unsigned long long , unsigned long long>
#define L 1000
#define N 10000
#define MOD 1000000007
char code[L+5];
char c[N+5][L+5];
int len[256],lenC[N+5];
hash hashMorse[256],hashCode[N+5],pow[L+5],codeHash[L+5];
int n,C,caso=0;
long long dp[L+5];
string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
void doit(){
    gets(c[0]);
    scanf("%s",code);
    codeHash[0]=make_pair(code[0]-'-'+1,code[0]-'-'+1);
    for(int i=1;code[i];++i)
        codeHash[i].first=(codeHash[i-1].first<<1)+codeHash[i-1].first+code[i]-'-'+1,
        codeHash[i].second=(codeHash[i-1].second<<1)+codeHash[i-1].second+code[i]-'-'+1,
        codeHash[i].second%=MOD;
    scanf("%d",&n);
    gets(c[0]);
    for(int i=0;i<n;++i)gets(c[i]);
    for(int i=0;i<n;++i){
        if(strlen(c[i])==0)hashCode[i]=make_pair(0,0);
        else hashCode[i]=hashMorse[c[i][0]];
        lenC[i]=len[ c[i][0] ];
        for(int j=1;c[i][j];++j)
            hashCode[i].first=hashCode[i].first*pow[ len[ c[i][j] ] ].first + hashMorse[ c[i][j] ].first,
            hashCode[i].second=hashCode[i].second*pow[ len[ c[i][j] ] ].second + hashMorse[ c[i][j] ].second,
            hashCode[i].second%=MOD,
            lenC[i]+=len[ c[i][j] ];
        }
    int m=strlen(code);
    memset(dp,0,sizeof(int)*m);
    dp[m]=1;
    for(int i=m-1;i>=0;--i){
        for(int j=0;j<n;++j){
            if(i+lenC[j]<=m){
                if(lenC[j]==0)continue;
                hash aux=codeHash[i+lenC[j]-1];
                if(i>0)aux.first=aux.first-codeHash[i-1].first*pow[ lenC[j] ].first,
                       aux.second=MOD+aux.second-(codeHash[i-1].second*pow[ lenC[j] ].second)%MOD,
                       aux.second%=MOD;
                if(hashCode[j]==aux)dp[i]+=dp[ i+lenC[j] ];
                }
            }
        }
    if(caso>0)printf("\n");
    ++caso;
    printf("%lld\n",dp[0]);
    }
int main(){
    for(int i='A',j=0;i<='Z';++i,++j){
        len[i]=morse[j].length();
        hashMorse[i]=make_pair(0,0);
        for(int k=0;k<len[i];++k)
            hashMorse[i].first=(hashMorse[i].first<<1)+hashMorse[i].first+morse[j][k]-'-'+1,
            hashMorse[i].second=(hashMorse[i].second<<1)+hashMorse[i].second+morse[j][k]-'-'+1,
            hashMorse[i].second%=MOD;
        }
    pow[0]=make_pair(1,1);
    for(int i=1;i<=L;++i)pow[i].first=(pow[i-1].first<<1)+pow[i-1].first,
                        pow[i].second=(pow[i-1].second<<1)+pow[i-1].second,
                        pow[i].second%=MOD;
    scanf("%d",&C);
    gets(c[0]);
    for(int i=0;i<C;++i)doit();
    }
