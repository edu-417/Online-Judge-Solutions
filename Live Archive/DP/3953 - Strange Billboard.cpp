#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 16
#define oo (1<<20)
int b[N+5];
int n,m;
int dp[N+5][N+5][(1<<N)+5][2];
bool used[N+5][N+5][(1<<N)+5][2];

int toMask(string s){
   int ans=0;
   for(int i=s.length()-1;i>=0;--i){
      ans<<=1;
      if(s[i]=='X')++ans;
      }
   return ans;
   }

void printMask(int mask){
    for(int i=0;i<m;++i)printf("%d",((mask>>i)&1)?1:0);
    printf("\n");
    }
int getMaskUsed(int mask,int idx,bool on){
   if((mask>>idx)&1)mask^=(1<<idx);
   mask^=(1<<idx);
   if(on)mask^=(1<<idx);
   if(idx>0)mask^=(1<<(idx-1));
   return mask;
   }

int getMask(int mask,int idx,bool on){
   if((mask>>idx)&1)mask^=(1<<idx);
   if(on)mask^=(1<<idx);
   return mask;
   }

int f(int x,int y,int mask,bool on){
    printf("x: %d y: %d\n",x,y);
    printMask(mask);
    printf("%d\n",on);
    if(x==n){
      if(mask==b[n-1])return 0;
      return oo;
      }
    if(y==m)return f(x+1,0,mask,false);
    int &ret=dp[x][y][mask][2];
    if(used[x][y][mask][2])return ret;
    used[x][y][mask][2]=true;
    if(x==0){
      int ans=min(1+ f(x,y+1,getMaskUsed(mask,y,on),true) , f(x,y+1,getMask(mask,y,on),false) );
      return ret=ans;
      }
      
    int last=b[x-1]^mask;
    if( (last>>y)&1 ){
      int ans=1+f( x,y+1,getMaskUsed(mask,y,on),true);
      return ret=ans;
      }
    int ans=f( x,y+1,getMask(mask,y,on),false);
    return ret=ans;
    }
char s[N+5];
bool doit(){
   scanf("%d%d",&n,&m);
   if(n==0 && m==0)return false;
   for(int i=0;i<n;++i){
        scanf("%s",s);
        b[i]=toMask(string(s));
        }
   for(int i=0;i<n;++i)printMask(b[i]);
   memset(used,false,sizeof(used));
   printf("%d\n",f(0,0,0,false));
   return true;
   }
   
int main(){
   while(1)if(!doit())break;
   }
