#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int n, m;
vector<int> adj[21];
long long dp[1<<20][21];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	dp[1][1] = 1;

	for(int s=2;s<(1<<n);s++){
		if(s&(1<<(n-1)) && s != ((1<<n)-1)) continue;
		for(int d=1;d<=n;d++){
			if((s&(1<<(d-1))) == 0) continue;
			for(int u:adj[d]){
				if(s&(1<<(u-1))){
					dp[s][d] += dp[s-(1<<(d-1))][u];
					dp[s][d] %= mod;
				}
			}
		}
	}

	cout << dp[(1<<n)-1][n]%mod;
}
