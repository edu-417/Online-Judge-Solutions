#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int x,a,b,c,n;
string s[100];
int rate[100],ind[100];
char cad[100];
bool used[100];
int ct[10];
void random(){
    x=(a*x+b)%c;
    }
bool comp(int l,int r){
    return rate[l]>rate[r];
    }
bool doit(){
    if(scanf("%d",&n)!=1)return false;
    scanf("%d%d%d%d",&x,&a,&b,&c);
    for(int i=0;i<n;++i){
        scanf("%s%d",cad,rate+i);
        s[i]=string(cad);
        }
    for(int i=0;i<n;++i)ind[i]=i;
    int m=n/4;
    for(int i=0;i<4;++i)ct[i]=m;
    sort(ind,ind+n,comp);
    for(int i=0;i<m-1;++i){
        printf("Group %c:\n",char('A'+i));
        for(int j=0;j<4;++j){
            random();
            int r=x%ct[j];
            for(int k=0,pos=j*m,q=0;k<m;++k,pos++){
                if(used[pos])continue;
                if(q==r){
                    used[pos]=true;
                    printf("%s\n",s[ind[pos]].c_str());
                    break;
                    }
                ++q;
                }
            ct[j]--;
            }
        }
    printf("Group %c:\n",char('A'+m-1));
    for(int i=0;i<4;++i){
        for(int j=0,pos=i*m;j<m;++j,++pos)
            if(used[pos])continue;
            else{
                used[pos]=true;
                printf("%s\n",s[ind[pos]].c_str());
                break;
                }
        ct[i]--;
        }
    return true;
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(1)if(!doit())break;
    }

