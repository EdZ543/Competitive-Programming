#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5+1;

int n;
vector<int> adj[MAXN];
long long dp[MAXN][2];
bool visited[MAXN];
long long d, nd;

void dfs(int v){
	visited[v] = true;
	dp[v][0] = 0;
	dp[v][1] = 1;
	for(int u:adj[v]){
		if(!visited[u]){
			dfs(u);
			if(dp[v][0]+dp[u][0]+1 > d){
				d = dp[v][0]+dp[u][0]+1;
				nd = dp[v][1]*dp[u][1];
			}else if(dp[v][0]+dp[u][0]+1 == d) nd += dp[v][1]*dp[u][1];
			if(dp[v][0] < dp[u][0]+1){
				dp[v][0] = dp[u][0]+1;
				dp[v][1] = dp[u][1];
			}else if(dp[v][0] == dp[u][0]+1) dp[v][1] += dp[u][1];
		}
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
	dfs(1);
	cout<<d+1<<" "<<nd;	
}
