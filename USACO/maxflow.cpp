#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1, LOG = 17;

int n, k, t = 0;
int milk[MAXN] = {0}, up[MAXN][LOG], st[MAXN], en[MAXN], ans[MAXN], s[MAXN], e[MAXN];
vector<int> adj[MAXN];

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

int dfs_ans(int cur = 1, int par = 1){
	int sum = 0;
	for(auto u:adj[cur]) if(u != par) sum += dfs_ans(u, cur);
	ans[cur] = sum+s[cur]-e[cur]/2;
	return sum+s[cur]-e[cur];
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	setIO("maxflow");

	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int x, y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs();
	while(k--){
		int a, b; cin>>a>>b;
		s[a]++;
		s[b]++;
		e[lca(a, b)] += 2;
	}
	dfs_ans();
	int sol = 0;
	for(int i=1;i<=n;i++) sol = max(sol, ans[i]);
	cout<<sol;
}
