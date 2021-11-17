#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int N;
vector<int> adj[MAXN];
int dp[MAXN][2];

void dfs(int v, int p){
	for(auto u:adj[v]){
		if(u != p){
			dfs(u, v);
			dp[v][0] += max(dp[u][0], dp[u][1]);
		}
	}
	for(auto u:adj[v]){
		if(u != p){
			dp[v][1] = max(dp[v][1], dp[u][0]+1+dp[v][0]-max(dp[u][0], dp[u][1]));
		}
	}
}

int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	dfs(1, -1);
	cout << max(dp[1][0], dp[1][1]);
}
