#include<cstdio>
#define N 20005
int n,C,caso=0;
int a[N];
void doit(){
    scanf("%d",&n);
    for(int i=0;i<n-1;++i)scanf("%d",a+i);
    int ans=a[0];
    int sum=0;
    int longitud=1;
    int inicio=0;
    int ini=0;
    for(int i=0;i<n-1;++i){
        if(ans<a[i])ans=a[i],longitud=1,inicio=i;
        if(sum+a[i]<0){
            sum=0;
            ini=i+1;
            continue;
            }
        sum+=a[i];
        if(ans==sum){
            if(longitud<(i-ini+1))longitud=i-ini+1,inicio=ini;
            }
        else if(ans<sum)ans=sum,longitud=i-ini+1,inicio=ini;
        }
    if(ans<=0)printf("Route %d has no nice parts\n",++caso);
    else printf("The nicest part of route %d is between stops %d and %d\n",++caso,inicio+1,inicio+longitud+1);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
