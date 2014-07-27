#include<cstdio>
int a,b,m,r;
int d[100005];
int main(){
    scanf("%d%d%d%d",&a,&b,&m,&r);
    int ans;
    for(int i=1;;++i){
        r=(a*r+b)%m;
        if(d[r]==0)d[r]=i;
        else{
            ans=i-d[r];
            break;
            }
        }
    printf("%d\n",ans);
    }
