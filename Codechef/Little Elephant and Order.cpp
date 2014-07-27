#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char c[2][20005];
int C;
void doit(){
    for(int i=0;i<2;++i)scanf("%s",c+i);
    int n=strlen(c[0]);
    int seven[2],four[2],lessfour[2],greatseven[2],in[2];
    for(int i=0;i<2;++i)seven[i]=four[i]=lessfour[i]=in[i]=greatseven[i]=0;
    for(int i=0;i<2;++i)
        for(int j=0;j<n;++j)
            if(c[i][j]>'7')++greatseven[i];
            else if(c[i][j]=='7')++seven[i];
            else if(c[i][j]>'4')++in[i];
            else if(c[i][j]=='4')++four[i];
            else ++lessfour[i];
    int ans=0;
    for(int i=0;i<2;++i)
        if( seven[i]<=in[1-i] )ans+=seven[i],in[1-i]-=seven[i],seven[i]=0,ans+=seven[i];
        else if( seven[i]<=lessfour[1-i]+in[1-i] )ans+=seven[i],lessfour[1-i]-=(seven[i]-in[1-i]),in[1-i]=seven[i]=0;
        else if( seven[i]<=lessfour[1-i]+in[1-i]+four[1-i] )ans+=seven[i],four[1-i]-=(seven[i]-in[1-i]-lessfour[1-i]),in[1-i]=lessfour[1-i]=seven[i]=0;
        else ans+=lessfour[1-i]+in[1-i]+four[1-i],seven[i]-=(lessfour[1-i]+four[1-i]+in[1-i]),lessfour[1-i]=four[1-i]=in[1-i]=0;
    string s="";
    ans+=min(seven[0],seven[1]);
    for(int i=0;i<ans;++i)s+='7';
    ans=0;
    for(int i=0;i<2;++i)
        if(four[i]<=lessfour[1-i])ans+=four[i],lessfour[1-i]-=four[i],four[i]=0;
        else ans+=lessfour[1-i],four[i]-=lessfour[1-i],lessfour[1-i]=0;
    if(four[0]<four[1])ans+=four[0];
    else ans+=four[1];
    for(int i=0;i<ans;++i)s+='4';
    printf("%s\n",s.c_str());
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
