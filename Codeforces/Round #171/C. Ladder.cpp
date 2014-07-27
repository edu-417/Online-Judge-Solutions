#include<cstdio>
#define N 100000
int n,m,s,e;
int a[N+5],p[N+5];

bool f(){
    if(p[--s]==p[--e])return true;
    if(s+1<n && p[s+1]==p[e] && a[s]<=a[s+1])return true;
    return false;
    }
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    p[0]=0;
    for(int i=1;i<n;++i){
        if(a[i-1]<=a[i]){
            p[i]=p[i-1];
            continue;
            }
        for(;i<n;++i){
            if(a[i-1]>=a[i]){
                p[i]=p[i-1];
                continue;
                }
            p[i]=p[i-1]+1;
            break;
            }
        }
    for(int i=0;i<m;++i){
        scanf("%d%d",&s,&e);
        printf("%s\n",f()?"Yes":"No");
        }
    }
