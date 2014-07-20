#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


pair<int,int> gcd(int a,int b){
    if(b==0)return make_pair(1,0);
    pair<int,int> aux = gcd(b,a%b);
    return make_pair(aux.second,aux.first-(a/b)*aux.second);
    }
bool isValid(int &a,const int &x,int &b,const int &y){
    if(a>=0 && b>=0)return true;
    int d=__gcd(x,y);
    int _x=x/d,_y=y/d;
    int l=(int)ceil(-a*1.0/_y);
    int r=(int)floor(b*1.0/_x);
    a=a+l*_y;
    b=b-l*_x;
    return l<=r;
    }
void fixed(int &_d,const int &d,int &c,const int &z){
    int l=(int)ceil(-_d*1.0/z);
    int r=(int)ceil(c*1.0/d);
    int t=max(l,r);
    _d=_d+t*z;
    c=c-t*d;
    }
bool doit(){
    int x,y,z,n;
    if(scanf("%d%d%d%d",&x,&y,&z,&n)!=4)return false;
    if(x==0 && y==0){
        if(n==0)printf("0 0 0\n");
        else printf("-1\n");
        }
    else{
        int d=__gcd(x,y);
        int g=__gcd(d,z);
        if(n%g>0)printf("-1\n");
        else{
            pair<int,int> aux=gcd(d,z);
            pair<int,int> aux2=gcd(x,y);
            int a=aux2.first,b=aux2.second,c=aux.second,_d=aux.first;
            printf("%d %d %d %d\n",a,b,_d,c);
            if(_d<=0)fixed(_d,d,c,z);
            int f=n/g;
            _d*=f,c*=f;
            a*=_d,b*=_d;
            printf("%d %d %d %d\n",a,b,_d,c);
            if(!isValid(a,x,b,y))printf("(%d, %d, %d, %d) \n",x,y,z,n);//printf("-1\n");
//          else if(a*x+b*y+c*z!=n)
            else printf("%d %d %d\n",a,b,-c);
  //          else printf("\n");
            }
        }
    return true;
    }
int main(){
//    for(int i=0;i<=10;++i)
//        for(int j=0;j<=10;++j)
//            for(int k=0;k<=10;++k)
//                for(int l=0;l<=10;++l)printf("%d %d %d %d\n",i,j,k,l);
    for(;doit(););
    }
