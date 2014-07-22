#include<cstdio>

#define N 300
#define M 2000
char pattern[N+5][N+5],text[M+5][M+5];
int n1,n2,m1,m2;
int border[N+5];
inline bool cmp(const int &x,const int &y){
    for(int i=0;i<n1;++i)if(pattern[i][x]!=pattern[i][y])return false;
    return true;
    }
inline bool cmp2(const int &x,const int &z,const int &y){
    for(int i=0;i<n1;++i)if(text[z+i][x]!=pattern[i][y])return false;
    return true;
    }
bool doit(){
    if(scanf("%d%d",&n1,&n2)!=2)return false;
    for(int i=0;i<n1;++i)scanf("%s",pattern[i]);
    scanf("%d%d",&m1,&m2);
    for(int i=0;i<m1;++i)scanf("%s",text[i]);

    for(int i=1;i<n2;++i){
        int j=border[i-1];
        while(j>0 && !cmp(i,j))j=border[j-1];
        if(cmp(i,j))++j;
        border[i]=j;
        }
    bool found = false;
    for(int k=0;k<m1-n1+1;++k){
        int j=0;
        for(int i=0;i<m2;++i){
            while(j>0 && !cmp2(i,k,j))j=border[j-1];
            if(cmp2(i,k,j))++j;
            if(j==n2){
                printf("(%d,%d)\n",k+1,i-n2+2);
                found=true;
                }
            }
        }
    if(!found)printf("NO MATCH FOUND...\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
