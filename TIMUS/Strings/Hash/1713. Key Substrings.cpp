#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
#define N 1000
#define K 100
#define MOD 10000
#define hash unsigned int
char s[N+5][K+5];
hash code[N+5][K+5];
hash pow[K+5];
vector<hash>  M[K+5][MOD+5];
int n;

bool count(int L,hash h){
    int idx=h%MOD;
    int ans=0;
    for(int i=0;i<M[L][idx].size();++i)if(M[L][idx][i]==h){
        ++ans;
        if(ans==2)return false;
        }
    return true;
    }
void f(int idx){
    int m=strlen(s[idx]);
    for(int L=1;L<=m;++L)
        for(int j=0;j+L<=m;++j){
            hash aux=code[idx][j+L]-pow[L]*code[idx][j];            
            if(count(L,aux)){
                for(int i=j;i<j+L;++i)putchar(s[idx][i]);
                printf("\n");
                return;
                }
            }
    }
int main(){
    pow[0]=1;
    for(int i=1;i<=K;++i)pow[i]=(pow[i-1]<<5)+pow[i-1];
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",s[i]);
    for(int i=0;i<n;++i){
        code[i][0]=0;
        for(int j=0;s[i][j];++j)code[i][j+1]=(code[i][j]<<5)+code[i][j]+s[i][j]-'a';
        }
    
    for(int i=0;i<n;++i){
        int m=strlen(s[i]);
        for(int L=1;L<=m;++L)
            for(int j=0;j+L<=m;++j){
                hash aux=code[i][j+L]-pow[L]*code[i][j];
                int idx=aux%MOD;
                M[L][idx].push_back(aux);
                }
        }
    
    for(int i=0;i<n;++i)f(i);
    }
