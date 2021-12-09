#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int h, w;
vector<string> grid;
vector<vector<int>> dp;

int paths(int r = 0, int c = 0){
	if(r == h-1 && c == w-1) return 1;
	if(dp[r][c] != -1) return dp[r][c];
	long long ret = 0;
	if(r+1 < h && grid[r+1][c] == '.') ret += paths(r+1, c);
	if(c+1 < w && grid[r][c+1] == '.') ret += paths(r, c+1);
	return dp[r][c] = ret%MOD;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>h>>w;
	dp.assign(h, vector<int>(w, -1));
	for(int i=0;i<h;i++){
		string row; cin>>row;
		grid.push_back(row);
	}

	cout<<paths();
}
