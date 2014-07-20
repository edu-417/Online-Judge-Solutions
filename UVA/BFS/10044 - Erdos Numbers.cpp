#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int p,q,C,n,n1;
string s;
map<string,int> M;
vector< string > nombre;
vector<vector<int> > L;
vector<int> d;
void bfs(){
    d.clear();
    d.resize(n,-1);
    d[M["Erdos, P."]]=0;
    queue<int> Q;
    Q.push(M["Erdos, P."]);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(size_t i=0;i<L[u].size();++i){
            int to=L[u][i];
            if(d[to]!=-1)continue;
            d[to]=d[u]+1;
            Q.push(to);
            }
        }
    }
    
void doit(){
    cin>>p>>q;
    getline(cin,s);
    n=0;
    L.clear();
    M.clear();
    for(int i=0;i<p;++i){
        getline(cin,s);
        nombre.clear();
        nombre.push_back("");
        n1=1;
        bool second=false;
        for(size_t j=0;j<s.length();++j)
            if(s[j]==','){
                if(second){
                    ++j;
                    if( M.find( nombre[n1-1] ) ==M.end())M[nombre[n1-1]]=n++;
                    nombre.push_back("");
                    ++n1;
                    }
                else nombre[n1-1]+=s[j];
                second^=true;
                }
            else if(s[j]==':'){
                if( M.find( nombre[n1-1] ) ==M.end())M[nombre[n1-1]]=n++;
                break;
                }
            else nombre[n1-1]+=s[j];
        L.resize(n);
        for(int j=0;j<n1;++j)
            for(int k=j+1;k<n1;++k)L[ M[ nombre[j] ] ].push_back( M[ nombre[k] ]),L[ M[ nombre[k] ] ].push_back( M[ nombre[j] ]);
        }
    if(M.find("Erdos, P.")==M.end())M["Erdos, P."]=n++;
    bfs();
    for(int i=0;i<q;++i){
        getline(cin,s);
        cout<<s<<" ";
        if(M.find(s)==M.end() || d[M[s]]==-1)cout<<"infinity\n";
        else cout<<d[M[s]]<<"\n";
        }
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin>>C;
    for(int i=0;i<C;++i){
        cout<<"Scenario "<<i+1<<"\n";
        doit();
        }
    }
