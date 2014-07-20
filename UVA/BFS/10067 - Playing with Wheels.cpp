#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
string start,end;

int n,C,x,num,source,sink;
bool f[10005];
int d[10005];
int bfs(){
    memset(d,-1,sizeof(d));
    queue<string> Q;
    d[source]=0;
    Q.push(start);
    while(!Q.empty()){
        string s=Q.front();
        Q.pop();
        int u=0;
        for(int j=0;j<4;++j)u*=10,u+=(s[j]-'0');

        for(int i=0;i<4;++i){
            string newS=s;
            newS[i]=char((s[i]-'0'+1)%10+'0');
            int to=0;
            for(int j=0;j<4;++j)to*=10,to+=(newS[j]-'0');
            if(f[to] || d[to]!=-1)continue;
            d[to]=d[u]+1;
            if(to==sink)return d[to];
            Q.push(newS);
            }

        for(int i=0;i<4;++i){
            string newS=s;
            newS[i]=char((s[i]-'0'+9)%10+'0');
            int to=0;
            for(int j=0;j<4;++j)to*=10,to+=(newS[j]-'0');
            if(f[to] || d[to]!=-1)continue;
            d[to]=d[u]+1;
            if(to==sink)return d[to];
            Q.push(newS);
            }
        }
    return d[sink];
    }
void doit(){
    memset(f,false,sizeof(f));
    num=0;
    start="";
    for(int j=0;j<4;++j)scanf("%d",&x),num*=10,num+=x,start+=char(x+'0');
    source=num;
    end="";
    num=0;
    for(int j=0;j<4;++j)scanf("%d",&x),num*=10,num+=x,end+=char(x+'0');
    sink=num;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        num=0;
        for(int j=0;j<4;++j)scanf("%d",&x),num*=10,num+=x;
        f[num]=true;
        }
    int ans=bfs();
    printf("%d\n",ans);
    }
int main(){
    scanf("%d",&C);
    for(int i=0;i<C;++i)doit();
    }
