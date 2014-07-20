#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 15
int n,m,k,x,y,caso=0;
vector<int> L[N],S[N];
vector< vector<int> > d,parentRoom,parentLights,action,switched;
vector< vector<bool> > used;
struct nodo{
    int room,lights;
    nodo(){}
    nodo(int _room,int _lights){
        room=_room;
        lights=_lights;
        }
    };
void rec(){
    int to=n-1,lights=(1<<(n-1));
    if(!used[to][lights])return;

    vector<int> pathRoom,pathLight,pathAction,pathSwitch;
    for(int uRoom=to,uLights=lights;uRoom!=-1;){
        int r=uRoom,l=uLights,a=action[r][l],s=switched[r][l];
        pathRoom.push_back(r);
        pathLight.push_back(l);
        pathAction.push_back(a);
        pathSwitch.push_back(s);
        uRoom=parentRoom[r][l];
        uLights=parentLights[r][l];
        }
    if(pathRoom.size()==1)return;
    for(size_t i=pathRoom.size()-2;i>0;--i){
        if(pathAction[i]==0)printf("- Move to room %d.\n",pathRoom[i]+1);
        else if(pathAction[i]==1)printf("- Switch on light in room %d.\n",pathSwitch[i]+1);
        else printf("- Switch off light in room %d.\n",pathSwitch[i]+1);
        }
    if(pathAction[0]==0)printf("- Move to room %d.\n",pathRoom[0]+1);
    else if(pathAction[0]==1)printf("- Switch on light in room %d.\n",pathSwitch[0]+1);
    else printf("- Switch off light in room %d.\n",pathSwitch[0]+1);
    }
int bfs(){
    d.clear();
    parentRoom.clear();
    parentLights.clear();
    used.clear();
    action.clear();
    switched.clear();
    d.resize( n, vector<int> ( (1<<n), -1) );
    parentRoom.resize( n, vector<int> ( (1<<n), -1) );
    parentLights.resize( n, vector<int> ( (1<<n), -1) );
    action.resize( n, vector<int> ( (1<<n), -1) );
    switched.resize( n, vector<int> ( (1<<n), -1) );
    used.resize( n, vector<bool> ( (1<<n), false) );
    int source=0,startLights=1;
    d[source][startLights]=0;
    used[source][startLights]=true;
    queue<nodo> Q;
    Q.push(nodo(source,startLights));
    while(!Q.empty()){
        nodo q=Q.front();
        Q.pop();
        int u=q.room,lights=q.lights;

        for(size_t i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(!((lights>>to)&1))continue;
            if(used[to][lights])continue;
            used[to][lights]=true;
            d[to][lights]=d[u][lights]+1;
            parentRoom[to][lights]=u;
            parentLights[to][lights]=lights;
            action[to][lights]=0;
            Q.push(nodo(to,lights));
            }
            
        for(size_t i=0;i<S[u].size();++i){
            int light=S[u][i];
            if(light==u)continue;
            int toLights=lights^(1<<light);
            if(used[u][toLights])continue;
            used[u][toLights]=true;
            d[u][toLights]=d[u][lights]+1;
            parentRoom[u][toLights]=u;
            parentLights[u][toLights]=lights;
            if( (lights>>light)&1 )action[u][toLights]=2;
            else action[u][toLights]=1;
            switched[u][toLights]=light;
            Q.push(nodo(u,toLights));
            }
        }
    return d[n-1][(1<<(n-1))];
    }
bool doit(){
    scanf("%d%d%d",&n,&m,&k);
    if(n==0 && m==0 && k==0)return false;
    for(int i=0;i<n;++i)L[i].clear(),S[i].clear();
    for(int i=0;i<m;++i)scanf("%d%d",&x,&y),L[--x].push_back(--y),L[y].push_back(x);
    for(int i=0;i<k;++i)scanf("%d%d",&x,&y),S[--x].push_back(--y);
    int ans=bfs();
    printf("Villa #%d\n",++caso);
    if(ans==-1)printf("The problem cannot be solved.\n");
    else{
        printf("The problem can be solved in %d steps:\n",ans);
        rec();
        }
    printf("\n");
    }
int main(){
    while(1)if(!doit())break;
    }
