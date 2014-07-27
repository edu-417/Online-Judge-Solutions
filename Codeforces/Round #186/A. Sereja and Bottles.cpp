#include<cstdio>
#define N 1000
bool used[N+5];
int a[N+5],b[N+5];
int cnt[N+5];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",a+i,b+i);
        ++cnt[a[i]];
        }
    for(int i=0;i<n;++i)if(a[i]!=b[i])used[b[i]]=true;
        else if(cnt[a[i]]>1)used[b[i]]=true;
    int ans=0;
    for(int i=0;i<n;++i)if(!used[a[i]])++ans;
    printf("%d\n",ans);
    }
