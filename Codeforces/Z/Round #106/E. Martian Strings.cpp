#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000
#define M 1000
char text[N+5],s[N+M+5],pattern[M+5];
int z[N+M+5],zr[N+M+5];
int q;
int main(){
    scanf("%s",text);
    for(int k=0;k<q;++k){
        scanf("%s",pattern);
        //s=pattern+$+text
        for(int i=0;pattern[i];++i)s[i]=pattern[i];
        int n=strlen(s);
        s[n++]='$';
        for(int i=0;text[i];++i)s[n++]=text[i];
        
        for(int i=1,l=0,r=0;i<n;++i){
            z[i]=0;
            if(i<=r)z[i]=min(r-i+1,z[i-l]);
            while(i+z[i]<n && s[i+z[i]]==s[z[i]])++z[i];
            if(i+z[i]-1>r)r=i+z[i]-1,l=i;
            }
            
        //s=reverse(pattern)+$+reverse(text)
        n=strlen(pattern);
        for(int i=n-1,j=0;i>=0;--i,++j)s[j]=pattern[i];
        s[n++]='$';
        int m=strlen(text);
        for(int i=m-1;i>=0;--i)s[n++]=text[i];
        
        for(int i=1,l=0,r=0;i<n;++i){
            zr[i]=0;
            if(i<=r)zr[i]=min(r-i+1,zr[i-l]);
            while(i+zr[i]<n && s[i+zr[i]]==s[zr[i]])++zr[i];
            if(i+zr[i]-1>r)r=i+zr[i]-1,l=i;
            }
        }
    }
