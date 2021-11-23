#include <bits/stdc++.h>
using namespace std;

int n, r, bridges = 0;
vector<int> adj[1001];
vector<pair<int, int>> edges;
vector<bool> visited;

bool con(int v, pair<int, int> edge){
	if(v == edge.second) return true;
	visited[v] = true;
	for(auto u:adj[v]) if(make_pair(v, u) != edge && !visited[u] && con(u, edge)) return true;
	return false;
}

bool good(){
	for(int i=0;i<edges.size();i++){
		visited.assign(n+1, false);
		if(!con(edges[i].first, edges[i])) return false;
	}
	return true;
}

pair<int, int> farthest(int v, vector<bool> visited){
	visited[v] = true;
	pair<int, int> ret = {v, 0};
	for(auto u:adj[v]){
		if(visited[u]) continue;
		auto next = farthest(u, visited);
		next.second++;
		if(next.second > ret.second) ret = next;
	}
	return ret;
}

int main(){
	cin >> n >> r;
	for(int i=0;i<r;i++){
		int	a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.push_back({a, b});
	}
	while(!good()){
		int a = farthest(1, vector<bool>(n+1, false)).first;
		int b = farthest(a, vector<bool>(n+1, false)).first;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.push_back({a, b});
		bridges++;
	}
	cout << bridges;
}
