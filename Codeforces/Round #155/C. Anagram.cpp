#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000
char s1[N+5],s2[N+5];
int cnt1[256],cnt2[256];
bool used[N+5];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i=0;s1[i];++i)++cnt1[s1[i]];
    for(int i=0;s2[i];++i)++cnt2[s2[i]];
    for(int i='A';i<='Z';++i){
        int x=min(cnt1[i],cnt2[i]);
        cnt1[i]-=x,cnt2[i]-=x;
        }
    int ans=0;
    for(int i='A';i<='Z';++i)ans+=cnt2[i];
    for(int i='A';i<='Z';++i){
        if(cnt2[i]>0){
            for(int j=0;s1[j];++j){
                if(cnt1[s1[j]]>0 && !used[j]&& s1[j]>char(i)){
                    used[j]=true;
                    --cnt2[i];
                    --cnt1[s1[j]];
                    s1[j]=char(i);
                    break;
                    }                                   
                }
            }
        }
    for(int i='Z';i>='A';--i){
        if(cnt2[i]>0){
            --cnt2[i];
            for(int j=strlen(s1)-1;j>=0;--j){
                if(cnt1[s1[j]]>0 && !used[j]){
                    used[j]=true;
                    --cnt1[s1[j]];
                    s1[j]=char(i);
                    break;
                    }                                   
                }
            }
        }
    printf("%d\n",ans);
    printf("%s\n",s1);
    }
