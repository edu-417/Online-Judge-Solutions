#include<cstdio>

int main(){
    int ans=0;
    for(int i=1;i<=5;++i)
        for(int j=i+1;j<=11-i;++j)ans+=i-1;
    for(int i=2;i<=5;++i)
        for(int j=12-i;j<=10;++j)ans+=10-j;
    for(int i=6;i<=9;++i)
        for(int j=i+1;j<=10;++j)ans+=10-j;
    printf("%d\n",ans);
    }
