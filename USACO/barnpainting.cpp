#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MOD 1000000007

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int n, k;
vector<int> adj[MAXN];
long long dp[MAXN][3];

void dfs(int cur = 1, int par = 0){
	for(auto u:adj[cur]) if(u != par){
		dfs(u, cur);
		dp[cur][0] *= dp[u][1]+dp[u][2];
		dp[cur][1] *= dp[u][0]+dp[u][2];
		dp[cur][2] *= dp[u][0]+dp[u][1];
		dp[cur][0] %= MOD;
		dp[cur][1] %= MOD;
		dp[cur][2] %= MOD;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	setIO("barnpainting");

	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int a, b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)dp[i][j]=1;
	for(int i=0;i<k;i++){
		int a, b; cin>>a>>b;
		dp[a][0] = dp[a][1] = dp[a][2] = 0;
		dp[a][b-1] = 1;
	}

	dfs();

	cout<<(dp[1][0]+dp[1][1]+dp[1][2])%MOD;
}
