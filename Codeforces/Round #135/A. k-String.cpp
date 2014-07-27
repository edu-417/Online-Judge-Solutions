#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int m;
char c[1005];
int let[256];
int main(){
    scanf("%d",&m);
    scanf("%s",c);
    int n=strlen(c);
    if(n%m!=0)printf("-1\n");
    else{
        for(int i=0;i<n;++i)++let[c[i]];
        bool val=true;
        string s(c);
        int p=n/m;
        int ini=0;
        for(int i='a';i<='z';++i)
            if(let[i]>0)
                if(let[i]%m!=0)val=false;
                else{
                    for(int k=0;k<let[i];k+=m,++ini)
                        for(int j=ini;j<n;j+=p)s[j]=char(i);
                    }
        if(!val)printf("-1\n");
        else printf("%s\n",s.c_str());
        }
    }
