#include<cstdio>
#include<cstring>
char s[100];
int c[7];
bool dp[5][5][5][5][5][5][32];
bool doit(){
    if(scanf("%s",s)!=1)return false;
    memset(c,0,sizeof(c));
    int sum=0;
    int n=0;
    for(n=0;s[n];++n)++c[s[n]-'0'],sum+=s[n]-'0';
    if(n&1)printf("%s %s\n",s,dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]][sum]?"B":"A");
    else printf("%s %s\n",s,dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]][sum]?"A":"B");
    return true;
    }
int main(){
    for(int c1=4;c1>=0;--c1)
    for(int c2=4;c2>=0;--c2)
    for(int c3=4;c3>=0;--c3)
    for(int c4=4;c4>=0;--c4)
    for(int c5=4;c5>=0;--c5)
    for(int c6=4;c6>=0;--c6)
        for(int i=31;i>=0;--i){
            bool ans=true;
            for(int j=1;j<=6 && i+j<=31;++j)
                if(j==1){if(c1<4)ans&=dp[c1+1][c2][c3][c4][c5][c6][i+j];}
                else if(j==2){if(c2<4)ans&=dp[c1][c2+1][c3][c4][c5][c6][i+j];}
                else if(j==3){if(c3<4)ans&=dp[c1][c2][c3+1][c4][c5][c6][i+j];}
                else if(j==4){if(c4<4)ans&=dp[c1][c2][c3][c4+1][c5][c6][i+j];}
                else if(j==5){if(c5<4)ans&=dp[c1][c2][c3][c4][c5+1][c6][i+j];}
                else if(j==6){if(c6<4)ans&=dp[c1][c2][c3][c4][c5][c6+1][i+j];}
            if(ans)dp[c1][c2][c3][c4][c5][c6][i]=false;
            else dp[c1][c2][c3][c4][c5][c6][i]=true;
            }
    while(1)if(!doit())break;
    }
