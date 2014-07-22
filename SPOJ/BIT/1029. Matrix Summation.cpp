#include<cstdio>
#include<cstring>
#define N 1024
int tree[N+5][N+5];
int A[N+5][N+5];
int n,C;
int x,y,a,b;
int val,ans;
char c[20];
void update(int x,int y,int val){
    int y1;
    while(x<=n){
        y1=y;
        while(y1<=n){
            tree[x][y1]+=val;
            y1+=(y1&-y1);
            }
        x+=(x&-x);
        }
    }

int query(int x,int y){
    int ans=0;
    int y1;
    while(x>0){
        y1=y;
        while(y1>0){
            ans+=tree[x][y1];
            y1-=(y1&-y1);
            }
        x-=(x&-x);
        }
    return ans;
    }
void doit(){
    scanf("%d",&n);
    for(int i=0;i<=n;++i)memset(A[i],0,sizeof(int)*(n+1));
    for(int i=0;i<=n;++i)memset(tree[i],0,sizeof(int)*(n+1));
    while(1){
        scanf("%s",c);
        if(strcmp(c,"END")==0)break;
        else if(strcmp(c,"SET")==0){
            scanf("%d%d%lld",&x,&y,&val);
            update(x+1,y+1,val-A[x+1][y+1]);
            A[x+1][y+1]=val;
            }
        else if(strcmp(c,"SUM")==0){
            scanf("%d%d%d%d",&x,&y,&a,&b);
            ans=(int)((long long)query(a+1,b+1)-query(a+1,y)+query(x,y)-query(x,b+1));
            printf("%d\n",ans);
            }
        }
    printf("\n");
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
