#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

int n;
vector<int> adj[MAXN];
int dp[3][MAXN];

void dfs1(int cur = 1, int par = -1){
	for(auto u:adj[cur]) if(u != par){
		dfs1(u, cur);
		if(dp[0][u]+1 > dp[0][cur]){
			dp[1][cur] = dp[0][cur];
			dp[0][cur] = dp[0][u]+1;
		}else if(dp[0][u]+1 > dp[1][cur]) dp[1][cur] = dp[0][u]+1;
	}
}

void dfs2(int cur = 1, int par = -1, int to_p = 0){
	dp[2][cur] = max(to_p, dp[0][cur]);
	for(auto u:adj[cur]) if(u != par){
		if(dp[0][u]+1 == dp[0][cur]) dfs2(u, cur, max(to_p, dp[1][cur])+1);
		else dfs2(u, cur, dp[2][cur]+1);
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

	for(int i=1;i<=n;i++) cout<<dp[2][i]<<"\n";
}
