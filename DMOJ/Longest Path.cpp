#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

int n, m;
vector<int> adj[MAXN];
int dp[MAXN];

void dfs(int x){
	dp[x] = 0;
	for(auto u:adj[x]){
		if(dp[u] == -1) dfs(u);
		dp[x] = max(dp[x], 1+dp[u]);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x, y; cin>>x>>y;
		adj[x].push_back(y);
	}

	memset(dp, -1, sizeof dp);
	for(int i=1;i<=n;i++) if(dp[i] == -1) dfs(i);

	int sol = 0;
	for(int i=1;i<=n;i++) sol = max(sol, dp[i]);
	cout<<sol;
}
