#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, p, q;
vector<int> adj[1000001];
vector<bool> visited(1000001);

bool dfs(int v, int target){
	if(v == target) return true;
	visited[v] = true;
	for(auto u : adj[v]){
		if(!visited[u]){
			if(dfs(u, target)) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	cin >> p >> q;
	visited.assign(1000001, false);
	bool yes = dfs(p, q);
	visited.assign(1000001, false);
	bool no = dfs(q, p);
	if(yes){
		cout << "yes\n";
	}else if(no){
		cout << "no\n";
	}else{
		cout << "unknown\n";
	}
}