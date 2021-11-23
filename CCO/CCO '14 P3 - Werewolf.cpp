#include <bits/stdc++.h>
using namespace std;

#define MAXN 201
#define MOD 1e9+7

int n, w, m;
vector<pair<int, char>> adj[MAXN];
int dp[MAXN][MAXN][2]; // let dp[a][b][c] be # of role assignments of robots from a to n with b werewolfs and c whether robot a is a werewolf or not

void dfs(int cur){
	dp[cur][0][0] = 1; // if no werewolfs and i'm not a werewolf, one assignment
	dp[cur][1][1] = 1; // if 1 werewolf and i'm a werewolf, one assignment

	for(auto u:adj[cur]){
		dfs(u.first);
		for(int i=w;i>=0;i--){
			long long is_w = 0, is_c = 0;
			for(int j=0;j<=i;j++){
				if(u.second == 'A') is_w += dp[cur][i-
				else 	
			}	
			dp[cur][i][0] = is_c;
			dp[cur][i][1] = is_w;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>w>>m;

	for(int i=0;i<m;i++){
		char op;
		int a, b;
		cin>>op>>a>>b;
		adj[a].push_back({b, op});
	}

	dfs(0);

	cout<<dp[0][w][0]%MOD;
}
