#include<cstdio>

#define N 300
#define M 2000
char pattern[N+5][N+5],text[M+5][M+5];
int n1,n2,m1,m2;
int border[N+5];
bool cmp(int x,int y){
    for(int i=0;i<n2;++i)if(pattern[x][i]!=pattern[y][i])return false;
    return true;
    }
bool cmp2(int x,int z,int y){
    for(int i=0;i<n2;++i)if(text[x][z+i]!=pattern[y][i])return false;
    return true;
    }
bool doit(){
    if(scanf("%d%d",&n1,&n2)!=2)return false;
    for(int i=0;i<n1;++i)scanf("%s",pattern[i]);
    scanf("%d%d",&m1,&m2);
    for(int i=0;i<m1;++i)scanf("%s",text[i]);
    
    for(int i=1;i<n1;++i){
        int j=border[i-1];
        while(j>0 && !cmp(i,j))j=border[j-1];
        if(cmp(i,j))++j;
        border[i]=j;
        }
    for(int i=0;i<n1;++i)printf("%d\n",border[i]);
    bool found = false;
    for(int k=0;k<m2-n2+1;++k){
        printf("K: %d\n",k);
        int j=0;
        for(int i=0;i<m1;++i){
            while(j>0 && !cmp2(i,k,j))j=border[j-1];
            if(cmp2(i,k,j))++j;
            if(j==n1){
                printf("(%d,%d)\n",i-n1+2,k+1);
                found=true;
                }
            }
        printf("\n");
        }
    if(!found)printf("NO MATCH FOUND...\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
