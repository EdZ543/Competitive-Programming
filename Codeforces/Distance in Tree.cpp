#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+1, MAXK = 501;

int n, k;
vector<int> adj[MAXN];
int dp1[MAXN][MAXK], dp2[MAXN][MAXK];

void dfs1(int cur = 1, int par = 0){
	for(int i=1;i<=k;i++) for(auto u:adj[cur]) if(u != par) dp2[cur][i] += dp2[u][i-1];
	dp2[cur][0] = 1;
}

void dfs2(int cur = 1, int par = 0){
	if(cur == 1) for(int i=0;i<=k;i++) dp1[cur][i] = dp2[cur][i];
	else for(int i=2;i<=k;i++) dp1[cur][i] = dp2[cur][i]+dp1[par][i-1]-dp2[cur][i-2];
	for(auto u:adj[cur]) if(u != par) dfs2(u, cur);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int a, b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1();
	dfs2();

	int sol = 0;
	for(int i=1;i<=n;i++) sol += dp1[i][k];
	cout<<sol;
}
