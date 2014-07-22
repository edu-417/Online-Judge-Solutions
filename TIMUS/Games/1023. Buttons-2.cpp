#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define N 10000
using namespace std;
bool prime[N+1];
int primo[1229];
int k;
int l(){
    for(int i=0;i<1229;i++)
        if(k%primo[i]==0)return primo[i]-1;
    if(k%2==0)return k/2 -1;
    return k-1;
    }
void doit(){
    printf("%d\n",l());
    }
void criba(){
    int ct=0;
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(long long i=2;i<=N;i++){
        if(prime[i]){
            primo[ct++]=i;
            for(long long j=i*i;j<=N;j+=i)prime[j]=false;
            }
        }
    }
int main(){
    criba();
    primo[0]=3;
    primo[1]=4;
    while(scanf("%d",&k)==1){
        doit();
        }
    }
