#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

int n;
vector<int> adj[MAXN];
long long dp[MAXN], sz[MAXN];
long long ans = 0;

void dfs1(int cur = 1, int par = -1){
	sz[cur] = 1;
	dp[cur] = 0;
	for(auto u:adj[cur]) if(u != par){
		dfs1(u, cur);
		sz[cur] += sz[u];
		dp[cur] += dp[u];
	}
	dp[cur] += sz[cur];
}

void dfs2(int cur = 1, int par = -1){
	ans = max(ans, dp[cur]);
	for(auto u:adj[cur])if(u != par){
		dp[cur] -= dp[u]+sz[u];
		sz[cur] -= sz[u];
		sz[u] += sz[cur];
		dp[u] += sz[cur]+dp[cur];
		dfs2(u, cur);
		dp[u] -= dp[cur]+sz[cur];
		sz[u] -= sz[cur];
		sz[cur] += sz[u];
		dp[cur] += sz[u]+dp[u];
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n-1;i++){
		int a, b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1();
	dfs2();

	cout<<ans;
}
