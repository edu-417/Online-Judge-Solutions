#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 10
#define L 10
#define NODES M*L
#define ALPH 256
#define MOD 100000
int n,m,nodes;
char * DNA ="ACGT";
int trie[NODES+5][ALPH];
bool end[NODES+5];
int border[NODES+5];
char s[L+5];

#define SIZE M*L

struct Matrix{
	int X[SIZE][SIZE];	
	Matrix(){}
	Matrix(int k){
		memset(X, 0, sizeof(X));		
		for(int i=0; i<SIZE; i++)X[i][i] = k;
	}
};

Matrix operator *(Matrix &A, Matrix &B){
	Matrix ans;	
	for(int i=0; i<nodes; i++)
		for(int j=0; j<nodes; j++){
			long long tmp = 0;
			for(int k=0; k<nodes; k++)tmp += (long long)A.X[i][k] * B.X[k][j];
			ans.X[i][j] = tmp % MOD;
		}	
	return ans;
}

Matrix pow(Matrix x, long long n){
	Matrix ans(1);	
	while(n>0){
		if(n & 1) ans = ans * x;		
		n >>= 1;
		x = x * x;
	}	
	return ans;
}
void add(char *s){
    int u=0;
    for(int i=0;s[i];++i){
        if(trie[u][s[i]]==0)trie[u][s[i]]=nodes++;
        u=trie[u][s[i]];
        }
    end[u]=true;
    }
void aho(){
    queue<int> Q;
    for(int i=0;i<4;++i){
        int u=trie[0][DNA[i]];
        if(u>0)Q.push(u);
        }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<4;++i){
            int to=trie[u][DNA[i]];
            int b=trie[border[u]][DNA[i]];
            if(to==0)trie[u][DNA[i]]=b;
            else Q.push(to),border[to]=b,end[to]|=end[b];
            }
        }
    }

void init(){
    nodes=1;
    }
int main(){
    scanf("%d%d",&m,&n);
    init();
    for(int i=0;i<m;++i)scanf("%s",s),add(s);
    aho();
    Matrix aux(0);
    for(int i=0;i<nodes;++i)
        for(int j=0;j<4;++j){
            int u=trie[i][DNA[j]];
            if(end[u])continue;
            ++aux.X[i][u];
            }
    aux=pow(aux,n);
    int ans=0;
    for(int i=0;i<nodes;++i)ans=ans+aux.X[0][i]*(!end[i]);
    ans%=MOD;
    printf("%d\n",ans);
    }
