#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, t, k, d, sol = INT_MAX;
vector<pair<int, int>> adj[5001];
vector<int> dist(5001);
vector<pair<int, int>> pencil_cities(5001);

void dijkstra(int v){
	dist.assign(5001, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[v] =  0;
	pq.push({0, v});

	while(pq.size()){
		int cdist, node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if(cdist != dist[node]) continue;
		for(auto u : adj[node]){
			if(cdist+u.second < dist[u.first]){
				pq.push({dist[u.first] = cdist+u.second, u.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> t;
	for(int i=0;i<t;i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}	
	cin >> k;
	for(int i=0;i<k;i++) cin >> pencil_cities[i].first >> pencil_cities[i].second;
	cin >> d;
	dijkstra(d);
	for(int i=0;i<k;i++) sol = min(sol, dist[pencil_cities[i].first]+pencil_cities[i].second);
	cout << sol << "\n";
}