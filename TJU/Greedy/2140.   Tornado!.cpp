#include<cstdio>
#include<iostream>
using namespace std;
#define N 5000
bool b[N+5];
int n;
bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)scanf("%d",b+i);
    bool zero=true;
    for(int i=0;i<n;++i)if(b[i])zero=false;
    if(zero){
        int ans=n/2+n%2;
        cout<<ans<<endl;
        return true;
        }
    int ans=0;
    for(int i=0;i<n;++i){
        if(!b[i]){
            int cnt=0;
            for(int j=i;j<n;++j,++i)if(b[i])break;
            else ++cnt;
            ans+=cnt/2;
            }
        }
    int cnt=0;
    if(!b[0] && !b[n-1]){
        for(int i=0;i<n;++i)if(b[i]){
            ans-=i/2;break;
            }
            else ++cnt;
        for(int i=n-1;i>=0;--i)if(b[i]){
            ans-=(n-1-i)/2;break;
            }
            else ++cnt;
        ans+=cnt/2;
        }
    cout<<ans<<endl;
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
