#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20001

int n;
vector<int> adj[MAX_N];
map<pair<int, int>, int> dp;

int size(int v, int prev){
	if(dp[{v, prev}]) return dp[{v, prev}];
	int total = 1;
	for(auto u:adj[v]){
		if(u == prev) continue;
		total += size(u, v);
	}
	dp[{v, prev}] = total;
	return total;
}

int balance(int v){
	int bal = 0;
	for(auto u:adj[v]){
		bal = max(bal, size(u, v));
	}
	return bal;
}

int main(){
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int minbal = INT_MAX, minnode;
	for(int i=1;i<=n;i++){
		int bal = balance(i);
		if(bal < minbal){
			minbal = bal;
			minnode = i;
		}
	}

	cout << minnode << ' ' << minbal;
}
