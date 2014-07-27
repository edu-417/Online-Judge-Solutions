#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000000
char s[N+5];
int z[N+5];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=1,l=0,r=0;i<n;++i){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])++z[i];
        if(i+z[i]-1>r)r=i+z[i]-1,l=i;
        }
    int maxZ=0,ans=0;
    for(int i=1;i<n;++i){
        if(z[i]==n-i && maxZ>=z[i]){
            ans=n-i;break;
            }
        maxZ=max(maxZ,z[i]);
        }
    if(ans==0)printf("Just a legend");
    else for(int i=0;i<ans;++i)putchar(s[i]);
    }
