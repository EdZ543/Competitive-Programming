#include <bits/stdc++.h>
using namespace std;
#define ll long long

int r, c, k;
vector<vector<bool>> has_cat(26, vector<bool>(26, false));
vector<vector<int>> dp(26, vector<int>(26, -1));

int dfs(pair<int, int> v){
	if(dp[v.first][v.second] != -1) return dp[v.first][v.second];
	int paths = 0;
	if(v == make_pair(r, c)) paths++;
	if(v.first < r && !has_cat[v.first+1][v.second]) paths += dfs({v.first+1, v.second});
	if(v.second < c && !has_cat[v.first][v.second+1]) paths += dfs({v.first, v.second+1});
	dp[v.first][v.second] = paths;
	return paths;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c >> k;
	for(int i=0;i<k;i++){
		int a, b; cin >> a >> b;
		has_cat[a][b] = true;
	}
	
	cout << dfs({1, 1}) << "\n";
}