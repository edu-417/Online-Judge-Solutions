#include<cstdio>
#define N 100000
int n,m,pos,val,op;
int a[N+5];
int s[N+5];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    int sum=0;
    for(int i=0;i<m;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&pos,&val);
            a[--pos]=val;
            s[pos]=-sum;
            }
        else if(op==2){
            scanf("%d",&val);
            sum+=val;
            }
        else{
            scanf("%d",&pos);
            --pos;
            long long ans=(long long)a[pos]+sum+s[pos];
            printf("%I64d\n",ans);
            }
        }
    }
