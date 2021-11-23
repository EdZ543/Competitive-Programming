#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> adj[10000];
vector<int> dp(10000, -1);

int paths(int v){
	if(dp[v] != -1) return dp[v];
	int sum = 0;
	for(auto u : adj[v]){
		sum += paths(u);
	}
	dp[v] = sum;
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while(true){
		int a, b; cin >> a >> b;
		if(a == 0 && b == 0) break;
		adj[a].push_back(b);
	}	
	dp[n] = 1;
	cout << paths(1) << "\n";
}