#include<cstdio>
int n,C;
void buildFarey(int ln,int ld,int rn,int rd){
    if(ld+rd>n)return;
    buildFarey(ln,ld,ln+rn,ld+rd);
    printf("%s%d/%d",ln+rn==1 && ld+rd==n?"":",",ln+rn,ld+rd);
    buildFarey(ln+rn,ld+rd,rn,rd);
    }
void doit(){
    scanf("%d",&n);
    buildFarey(0,1,1,1);
    printf("\n");
    }
    
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
