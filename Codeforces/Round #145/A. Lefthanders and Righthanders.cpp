#include<cstdio>

int n;
char c[1000];
int left[1000],right[1000];
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    scanf("%s",c);
    for(int i=0;i<n/2;++i)if(c[i]=='R' && c[n/2+i]=='L')printf("%d %d\n",n/2+i+1,i+1);
    else printf("%d %d\n",i+1,n/2+i+1);
    return true;
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(1)if(!doit())break;
    }

