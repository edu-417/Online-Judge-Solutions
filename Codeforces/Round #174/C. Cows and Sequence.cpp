#include<cstdio>
#define N 200000
int n,m,x,q,t;
long long sum;
int a[N+5];
long long s[N+5];
void query1(){
    scanf("%d%d",&m,&x);
    sum+=m*x;
    s[--m]+=x;
    }
void query2(){
    scanf("%d",&x);
    a[n++]=x;
    sum+=x;
    }
void query3(){
    if(n<2)return;
    sum-=s[n-1];
    sum-=a[n-1];
    a[--n]=0;
    s[n-1]+=s[n];
    s[n]=0;
    }
int main(){
    n=1;
    sum=0;
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d",&t);
        if(t==1)query1();
        else if(t==2)query2();
        else query3();
        printf("%.6lf\n",sum*1.0/n);
        }
    }
