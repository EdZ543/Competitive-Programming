#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

int n, m, a, b, q;
vector<pair<int, int>> adj[2][MAXN];
vector<vector<int>> edges;
int dist[2][MAXN];

void dijkstra(int src, int ind){
	for(int i=1;i<=n;i++) dist[ind][i] = INT_MAX;

	using T = pair<int, int>; priority_queue<T, vector<T>, greater<T>> pq;
	dist[ind][src] = 0;
	pq.push({0, src});

	while(!pq.empty()){
		int cdist, cnode; tie(cdist, cnode) = pq.top(); pq.pop();
		if(cdist != dist[ind][cnode]) continue;

		for(auto u:adj[ind][cnode]){
			if(cdist+u.second < dist[ind][u.first]){
				pq.push({dist[ind][u.first] = cdist+u.second, u.first});
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>a>>b;

	for(int i=0;i<m;i++){
		int x, y, l, c; cin>>x>>y>>l>>c;
		adj[0][x].push_back({y, l});
		adj[1][y].push_back({x, l});
		edges.push_back({x, y, l, c});
	}

	dijkstra(a, 0);
	dijkstra(b, 1);

	cin>>q;
	int sol[q];
	vector<pair<int, int>> queries;
	for(int i=0;i<q;i++){
		int d; cin>>d;
		queries.push_back({d, i});
	}
	sort(queries.begin(), queries.end());

	vector<pair<int, int>> edgedists;
	for(auto edge:edges){
		int dist1 = dist[0][edge[0]];
		int dist2 = dist[1][edge[1]];
		if(dist1 == INT_MAX || dist2 == INT_MAX) continue;
		edgedists.push_back({dist1+edge[2]+dist2, edge[3]});
	}
	sort(edgedists.begin(), edgedists.end());

	int ind = 0;
	int cost = 0;
	for(int i=0;i<edgedists.size();i++){
		while(ind < q && edgedists[i].first > queries[ind].first){
			sol[queries[ind++].second] = cost;
		}
		cost += edgedists[i].second;
	}
	while(ind < q){
		sol[queries[ind++].second] = cost;
	}
	
	for(int i=0;i<q;i++) cout<<sol[i]<<"\n";
}
