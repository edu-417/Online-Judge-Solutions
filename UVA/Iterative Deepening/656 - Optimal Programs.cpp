#include<cstdio>
#include<stack>
#include<string>
#include<vector>
using namespace std;
#define N 15
vector <int> S[N];
vector <string> ans;
int x,n,caso=0;
int end[N];
bool solution;
void back(int depth){
    if(solution)return;
    if(depth==0){
        bool val=true;
        for(int i=0;i<n;++i)if(S[i].back()!=end[i]){
            val=false;
            break;
            }
        if(val){
            if(ans.size()==0)printf("Empty sequence");
            for(int i=0;i<ans.size();++i)printf("%s%s",i==0? "":" ",ans[i].c_str());
            printf("\n");
            solution=true;
            }
        return;
        }
        
    int a[n];
    bool val=true,val3=true;
    
    for(int i=0;i<n;++i){
        a[i]=S[i].back(),S[i].pop_back();
        if(S[i].size()==0)val3=false;
        if(a[i]>30000 || a[i]<-30000)val=false;
        }
    int b[n];
    if(!val){
        for(int i=0;i<n;++i)S[i].push_back(a[i]);
        return;
        }
            
    if(val3){
        for(int i=0;i<n;++i)b[i]=S[i].back(),S[i].pop_back();
        
        for(int i=0;i<n;++i)S[i].push_back(a[i]+b[i]);
        ans.push_back("ADD");
        back(depth-1);
        ans.pop_back();
        for(int i=0;i<n;++i)S[i].pop_back();
    
        bool val2=true;
        for(int i=0;i<n;++i)if(a[i]==0){
            val2=false;
            break;
            }
        if(val2){
            for(int i=0;i<n;++i)S[i].push_back(b[i]/a[i]);
            ans.push_back("DIV");
            back(depth-1);
            ans.pop_back();
            for(int i=0;i<n;++i)S[i].pop_back();
            }
            
        for(int i=0;i<n;++i)S[i].push_back(b[i]);
        
        }
        
    for(int i=0;i<n;++i)S[i].push_back(a[i]);
    
    for(int i=0;i<n;++i)S[i].push_back(S[i].back());
    ans.push_back("DUP");
    back(depth-1);
    ans.pop_back();
    for(int i=0;i<n;++i)S[i].pop_back();
    
    for(int i=0;i<n;++i)S[i].pop_back();
    if(val3)for(int i=0;i<n;++i)S[i].pop_back();
    
    if(val3){
        for(int i=0;i<n;++i)S[i].push_back(a[i]*b[i]);
        ans.push_back("MUL");
        back(depth-1);
        ans.pop_back();
        for(int i=0;i<n;++i)S[i].pop_back();
        
        for(int i=0;i<n;++i)S[i].push_back(b[i]-a[i]);
        ans.push_back("SUB");
        back(depth-1);
        ans.pop_back();
        for(int i=0;i<n;++i)S[i].pop_back();
        
        for(int i=0;i<n;++i)S[i].push_back(b[i]);
        }
    for(int i=0;i<n;++i)S[i].push_back(a[i]);
    }

bool doit(){
    scanf("%d",&n);
    if(n==0)return false;
    for(int i=0;i<n;++i)S[i].clear();
    ans.clear();
    for(int i=0;i<n;++i)scanf("%d",&x),S[i].push_back(x);
    for(int i=0;i<n;++i)scanf("%d",end+i);
    int depth=0;
    solution=false;
    printf("Program %d\n",++caso);
    while(1){
        if(depth==11 || solution)break;
        back(depth);
        depth++;
        }
    if(!solution)printf("Impossible\n");
    printf("\n");
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
