#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000

int a[N + 5], ind[N + 5], pos[N + 5];
bool used[N + 5];

bool cmp(int idx, int idy){
    return a[idx] < a[idy];
}

int n, caso;

bool doCase(){
    scanf("%d",&n);
    if(n == 0)return false;
    
    for(int i = 0; i < n; ++i)scanf("%d", a + i);
    for(int i = 0; i < n; ++i)ind[i] = i;
    sort(ind, ind + n, cmp);

    for(int i = 0; i < n ; ++i)pos[ind[i]] = i;

    memset(used, false, sizeof(bool) * n );
    int ans = 0;
    for(int i = 0; i < n ; ++i){
        if(used[i])continue;        
        int cnt = 1;
        int aux = 0, opc = a[ind[0]] + a[ind[i]];
        used[i]= true;
        for(int prev = pos[i] ; prev != i; prev = pos[prev], ++cnt)used[prev] = true;
        aux += (cnt - 1) * a[ind[i]];
        opc += cnt * a[ind[0]];
        opc += a[ind[i]];
        for(int prev = pos[i] ; prev != i; prev = pos[prev])aux += a[ind[prev]], opc += a[ind[prev]];
        if( i > 0)aux = min(aux, opc);
        ans += aux;
    }
    printf("Case %d: %d\n\n", ++caso, ans);
    return true;
}
int main(){
    caso = 0;
    while(1)if(!doCase())break;      
}
