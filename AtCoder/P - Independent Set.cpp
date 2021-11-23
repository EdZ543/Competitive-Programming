#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e5+1;
const long long MOD = 1e9+7;

long long N;
vector<long long> adj[MAXN];
long long dp[MAXN][2];

void dfs(long long v, long long p){
	for(auto u:adj[v]){
		if(u != p){
			dfs(u, v);
			dp[v][0] = (dp[v][0]*dp[u][1])%MOD;
		}
	}	
	for(auto u:adj[v]){
		if(u != p){
			dp[v][1] = (dp[v][1]*(dp[u][0]+dp[u][1]))%MOD;
		}
	}
}

int main(){
	cin >> N;
	for(long long i=0;i<N-1;i++){
		long long x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(long long i=0;i<MAXN;i++) for(long long j=0;j<2;j++) dp[i][j] = 1;
	dfs(1, -1);
	cout << (dp[1][0]+dp[1][1])%MOD;
}
