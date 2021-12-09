#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void add_self(int& a, int b){
	a = (a+b)%mod;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;

	vector<vector<int>> con(n, vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>con[i][j];
		}
	}

	vector<int> dp(1<<n);
	dp[0] = 1;

	for(int mask=0;mask<(1<<n)-1;mask++){
		int i = __builtin_popcount(mask);
		for(int j=0;j<n;j++){
			if(!con[i][j] || mask&(1<<j)) continue;
			int mask2 = mask|(1<<j);
			add_self(dp[mask2], dp[mask]);	
		}
	}

	cout<<dp[(1<<n)-1];
}
