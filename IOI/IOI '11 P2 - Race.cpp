#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000

int n, k;
vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];

int dfs(int v, int h, int l){
	if(l == k) return h;
	if(l > k) return INT_MAX;

	visited[v] = true;
	int ret = INT_MAX;
	for(auto u:adj[v]){
		if(visited[u.second]) continue;
		ret = min(ret, dfs(u.second, h+1, l+u.first));
	}

	return ret;	
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n-1;i++){
		int a, b, l; cin >> a >> b >> l;
		adj[a].push_back({l, b});
		adj[b].push_back({l, a});
	}

	int sol = INT_MAX;
	for(int i=0;i<n;i++){
		memset(visited, false, sizeof(visited));
		sol = min(sol, dfs(i, 0, 0));
	}

	cout << (sol == INT_MAX ? -1 : sol);
}
