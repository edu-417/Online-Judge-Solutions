#include<cstdio>
#include<vector>
using namespace std;
#define N 40000000
vector<bool> prime;
void criba(){
    prime.resize(N+1,true);
    for(int i=2;i<=N/i;++i)
        if(prime[i])for(int j=i*i;j<=N;j+=i)prime[j]=false;
    }
int main(){
    criba();
    for(int i=30000001;i<N;i+=2)if(prime[i])printf("%d\n",i);
    }
