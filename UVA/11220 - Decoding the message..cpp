#include<cstdio>
#include<string>
using namespace std;
string s[100];
char c[1000],c1[100];
int C,caso=0;
void doit(){
    if(caso>0)printf("\n");
    printf("Case #%d:\n",++caso);
    while(1){
        gets(c);
        if(string(c)=="")break;
        int n=0;
        int ct=0,Ct=0;
        while(1){
            if(sscanf(c+Ct,"%s%n",c1,&ct)!=1)break;
            s[n++]=string(c1);
            Ct+=ct;
            }
        string ans="";
        for(int i=0,j=0;j<n;++j){
            if(s[j].length()<=i){
                continue;
                }
            ans+=s[j][i];
            ++i;
            }
        printf("%s\n",ans.c_str());
        }
    }
int main(){
    scanf("%d",&C);
    gets(c);
    gets(c);
    for(int i=0;i<C;++i)doit();
    }
