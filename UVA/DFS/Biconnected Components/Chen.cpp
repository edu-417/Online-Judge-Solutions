#include <iomanip>
#include <numeric>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <queue>
#define f(i,x,y) for(int i=x;i<y;i++)
#define fd(i,y,x) for(int i=y;i>=x;i--)
#define FOR(it,A) for( typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define impr(A) for( typeof A.begin() chen = A.begin(); chen !=A.end(); chen++ ) cout<<*chen<<" "; cout<<endl
#define ll long long
#define vint vector<int>
#define clr(A,x) memset(A,x,sizeof(A))
#define CLR(v) f(i,0,n) v[i].clear()
#define oo (1<<30)
#define ones(x) __builtin_popcount(x)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define eps (1e-9)
#define cua(x) (x)*(x)
#define MAX 100005
#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
using namespace std;

int n,m,fin;
int orig[MAX], dest[MAX], pila[MAX], top = 0;
vint E[MAX];
int low[MAX], dfsn[MAX], part[MAX], timer;
int ponte[MAX], bicomp[MAX], nbicomp;

int dfsbcc (int u, int p = -1){
	low[u] = dfsn[u] = ++timer;
	int ch = 0;
	FOR(it, E[u]){
		int e = *it, v = VIZ (e, u);
		if (dfsn[v] == 0){
			pila[top++] = e;
			dfsbcc (v, u);
			low[u] = min (low[u], low[v]);
			ch++;
			if (low[v] >= dfsn[u]){
				part[u] = 1;
				nbicomp++;
				do{
					fin = pila[--top];
					bicomp[fin] = nbicomp;
				}while (fin != e);
			}
			if (low[v] == dfsn[v]) ponte[e] = 1;
		}else if (v!=p && dfsn[v] < dfsn[u]){
			pila[top++] = e;
			low[u] = min (low[u], dfsn[v]);
		}
	}
	return ch;
}
void bcc (){
	f(i,0,n) part[i] = dfsn[i] = 0;
	f(i,0,m) ponte[i] = 0;
	nbicomp = timer = 0;
	f(i,0,n) if (dfsn[i] == 0) part[i] = dfsbcc (i) >= 2;
}

int main()
{
	cin >> n >> m;
	f(i,0,m){
		int u,v; cin >> u >> v; u--; v--;
		orig[i] = u;
		dest[i] = v;
		E[u].pb (i);
		E[v].pb (i);
	}
	bcc();
	f(i,0,n) cout << part[i]; cout << endl;
	f(i,0,m) cout << ponte[i]; cout << endl;
	f(i,0,m) cout << bicomp[i]; cout << endl;
}
