#include<cstdio>
#define N 100000
int n;
int a[N+5];
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    int sum1=0,sum2=0,sum3=0;
    bool ans=true;
    for(int i=0;i<n;++i){
        if(a[i]==25)sum1+=25;
        if(a[i]==50){
            if(sum1<25)ans=false;            
            else sum1-=25;
            sum2+=50;
            }
        if(a[i]==100){
            if(sum1<25)ans=false;
            if(sum1+sum2<75)ans=false;
            if(sum2>=50){
                sum1-=25;
                sum2-=50;
                }            
            else if(sum1>=75)sum1-=75;
            }
        }
    printf("%s\n",ans?"YES":"NO");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
