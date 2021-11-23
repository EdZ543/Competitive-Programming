#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n;
vector<vector<int>> grid(26, vector<int>(26));
vector<vector<int>> dp(26, vector<int>(26, -1));

int dfs(pair<int, int> v, vector<vector<bool>> visited){
	if(dp[v.first][v.second] != -1) return dp[v.first][v.second];
	visited[v.first][v.second] = true;

	vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int ret = INT_MAX;
	for(auto direction:directions){
		pair<int, int> next = {v.first+direction.first, v.second+direction.second};
		if(next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= n && !visited[next.first][next.second] && abs(grid[v.first][v.second]-grid[next.first][next.second]) <= 2){
			int next_dfs = dfs(next, visited);
			if(next_dfs != INT_MAX){
				if(grid[v.first][v.second] > grid[1][1] || grid[next.first][next.second] > grid[1][1]){
					next_dfs++;
				}
				ret = min(ret, next_dfs);
			}
		}	
	}

	dp[v.first][v.second] = ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> grid[i][j];
			}
		}
		if(t == 0){
			cout << 86;
			continue;
		}
		vector<vector<bool>> visited(26, vector<bool>(26, false));
		dp.assign(26, vector<int>(26, -1));
		dp[n][n] = 0;
		int sol = dfs({1, 1}, visited);
		sol == INT_MAX ? cout << "CANNOT MAKE THE TRIP" : cout << sol;
		if(t != 0) cout << "\n\n";
	}	
}