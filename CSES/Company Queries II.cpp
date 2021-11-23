#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1, LOG = 18;

int n, q;
int up[MAXN][LOG];
vector<int> adj[MAXN];
int st[MAXN], en[MAXN];
int t = 0;

void dfs(int x = 1, int par = 1){
	st[x] = t++;
	up[x][0] = par;
	for(int i=1;i<LOG;i++) up[x][i] = up[up[x][i-1]][i-1];
	for(auto u:adj[x]) if(u != par) dfs(u, x);
	en[x] = t-1;	
}

bool anc(int a, int b){
	return st[a] <= st[b] && en[a] >= en[b];
}

int lca(int a, int b){
	if(anc(a, b)) return a;
	if(anc(b, a)) return b;
	for(int i=LOG-1;i>=0;i--) if(!anc(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x; cin>>x;
		adj[x].push_back(i);
	}

	dfs();

	while(q--){
		int a, b; cin>>a>>b;
		cout<<lca(a, b)<<"\n";
	}
}
