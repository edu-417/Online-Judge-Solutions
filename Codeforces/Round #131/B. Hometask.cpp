#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int a[100005];
int dig[10];
int n;
void doit(){
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;++i)scanf("%d",a+i),++dig[a[i]],sum+=a[i];
    int d=sum%3;
    bool b=false;
    if(d==0)b=true;
    for(int i=1;i<10;++i)
        if(d==0)break;
        else if(i%3==d && dig[i]>0){
        --dig[i];
        b=true;
        break;
        }
    string ans="";
    for(int i=0;i<10;++i)
        for(int j=0;j<dig[i];++j)ans=char(i+'0')+ans;
    if(dig[0]==0)ans="-1";
    while(1){
        if(ans[0]=='0')ans.erase(0);
        else break;
        }
    if(ans=="")ans="0";
    printf("%s\n",ans.c_str());
    }
int main(){
    doit();
    }
