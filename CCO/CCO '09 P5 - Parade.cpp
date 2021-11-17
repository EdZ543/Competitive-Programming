#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

struct change{
	int r, c, k;
};

int n, q;
change changes[MAXN];
vector<vector<int>> dp[MAXN];

vector<vector<int>> apply_change(vector<vector<int>> grid, change ch){
	vector<vector<int>> ngrid = grid;
	int r = ch.r, c = ch.c, k = ch.k;

	for(int j=c+1;j<c+k;j++) ngrid[r][j] = grid[r][j-1];
	for(int i=r+1;i<r+k;i++) ngrid[i][c+k-1] = grid[i-1][c+k-1];
	for(int j=c+k-2;j>=c;j--) ngrid[r+k-1][j] = grid[r+k-1][j+1];
	for(int i=r+k-2;i>=r;i--) ngrid[i][c] = grid[i+1][c];

	return ngrid;
}

void init(){
	dp[0].assign(5, vector<int>(5));
	int cnt = 1;
	for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) dp[0][i][j] = cnt++;
	for(int i=1;i<=n;i++) dp[i] = apply_change(dp[i-1], changes[i]);
}

void update(int ind, change ch){
	changes[ind] = ch;
	for(int i=ind;i<=n;i++) dp[i] = apply_change(dp[i-1], changes[i]);

	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<dp[n][i][j];
			if(j != 4) cout<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int r, c, k; cin>>r>>c>>k;
		changes[i] = {r, c, k};
	}
	
	init();

	while(q--){
		int i, r, c, k; cin>>i>>r>>c>>k;
		update(i, {r, c, k});
	}
}
