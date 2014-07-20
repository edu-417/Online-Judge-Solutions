#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


pair<int,int> gcd(int a,int b){
    if(b==0)return make_pair(1,0);
    pair<int,int> aux = gcd(b,a%b);
    return make_pair(aux.second,aux.first-(a/b)*aux.second);
    }
void validate(int &a,int x,int &b,int y){
    int d=__gcd(x,y);
    x/=d;y/=d;
    if(a<=0 && b>=0)return;
    int l=(int)ceil(a*1.0/y);
    int r=(int)ceil(-b*1.0/x);
    int t=max(l,r);
    a=a-t*y;
    b=b+t*x;
    }
void validate2(int &a,int x,int &b,int y){
    int d=__gcd(x,y);
    x/=d;y/=d;
    if(a>=0 && b<=0)return;
    int l=(int)ceil(-a*1.0/y);
    int r=(int)ceil(b*1.0/x);
    int t=max(l,r);
    a=a+t*y;
    b=b-t*x;
    }
bool doit(){
    int x,y,z,n;
    if(scanf("%d%d%d%d",&x,&y,&z,&n)!=4)return false;
    //printf("(x,y,z,n) : %d %d %d %d\n",x,y,z,n);
    if(x==0 && y==0){
        if(n==0)printf("0 0 0\n");
        else printf("-1\n");
        }
    else if(x==0){
        int g=__gcd(y,z);
        pair<int,int> aux=gcd(y,z);
        int a=0,b=aux.first,c=aux.second;
        if(n%g==0){
            validate2(b,y,c,z);
            int f=n/g;
            b*=f;c*=f;
            printf("%d %d %d\n",a,b,-c);
            }
        else printf("-1\n");
        }
    else if(y==0){
        int g=__gcd(x,z);
        pair<int,int> aux=gcd(x,z);
        int b=0,a=aux.first,c=aux.second;
        if(n%g==0){
            validate2(a,x,c,z);
            int f=n/g;
            a*=f;c*=f;
            printf("%d %d %d\n",a,b,-c);
            }
        else printf("-1\n");        
        }
    else{
        int m=__gcd(y,z);
        int g=__gcd(x,m);
        if(n%g==0){
        pair<int,int> aux=gcd(y,z);
        pair<int,int> aux2=gcd(x,m);
        int a=aux2.first,b=aux.first,c=aux.second,_m=aux2.second;
        //printf("(b , c) : %d %d\n",b,c);
        //printf("(a , _m) : %d %d\n",a,_m);
        if(_m==0)b=0,c=0;
        else{
            int f=n/g;
            validate(b,y,c,z);
            validate2(a,x,_m,m);
            //printf("(b , c) : %d %d\n",b,c);
            //printf("(a , _m) : %d %d\n",a,_m);
            a*=f;_m*=f;
            b*=_m;c*=_m;
            }
        printf("%d %d %d\n",a,b,-c);
        }
        else printf("-1\n");
    }
    return true;
    }
int main(){
    for(;doit(););
    }
