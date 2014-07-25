#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
#define N 1000
#define oo INT_MAX
bool dry[N+5][N+5];
int d[N+5][N+5];
int n, m, sx, sy, ex, ey, r1, c1, r2, c2, w;

const int cost[][5] = {
    {7,6,5,6,7},
    {6,3,2,3,6},
    {5,2,0,2,5},
    {6,3,2,3,6},
    {7,6,5,6,7}
};

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
    }
    
void dijkstra(){    
    for(int i= 0; i< n ; ++i)
        for( int j = 0; j< m ;++j)d[i][j]=oo;
        
    d[sx][sy]=0;
    
    priority_queue< pair<int, pair<int,int> > > Q;
    Q.push( make_pair(0, make_pair(sx,sy) ) );
    
    while(!Q.empty()){
        int ux=Q.top().second.first;
        int uy=Q.top().second.second;
        int cur_d=-Q.top().first;
        Q.pop();
        if(cur_d>d[ux][uy])continue;
        for(int i = -2 ;i <= 2;++i)
            for(int j = -2 ;j <= 2 ;++j){
                int tox=ux+i;
                int toy=uy+j;
                if(!isValid(tox,toy))continue;
                if(!dry[tox][toy])continue;
                int len=cost[i+2][j+2];
                if(d[ux][uy]+len<d[tox][toy]){
                    d[tox][toy]=d[ux][uy]+len;
                    Q.push(make_pair(-d[tox][toy],make_pair(tox,toy)));
                    }
                }
        }
    }
    

bool doCase(){
    scanf("%d%d",&n,&m);
    if(n == 0 && m == 0)return false;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    --sx,--sy,--ex,--ey;
    scanf("%d",&w);
    
    memset(dry,true,sizeof(dry));
    for(int i = 0; i< w ; ++i){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        --c1,--r1,--c2,--r2;
        for(int j = r1 ; j <= r2;  ++j)
            for(int k = c1; k <= c2 ; ++k)dry[j][k] = false;
        }
    dijkstra();
    if(d[ex][ey] == oo) printf("impossible\n");
    else printf("%d\n",d[ex][ey]);
    return true;
    }
    
int main(){
    while(1)if(!doCase())break;
    }
