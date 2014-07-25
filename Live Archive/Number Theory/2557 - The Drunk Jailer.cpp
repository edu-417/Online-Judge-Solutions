#include<cstdio>

int n,C;
int sqrt(int n){
    int lo=1,hi=n;
    while(lo<hi){
        int mid=lo+((hi-lo+1)>>1);
        if(mid*mid>n)hi=mid-1;
        else lo=mid;
        }
    return lo;
    }
void doit(){
    scanf("%d",&n);
    printf("%d\n",sqrt(n));
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
