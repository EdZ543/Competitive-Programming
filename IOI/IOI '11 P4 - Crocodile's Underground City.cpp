#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
vector<pair<long long, long long>> adj[100000];
long long exs[100000];
long long vis[100000] = {0};

long long dijkstra(long long v){
	using T = pair<long long, long long>;
	priority_queue<T, vector<T>, greater<T>> pq;
	for(long long i=0;i<k;i++){
		pq.push({0, exs[i]});
		vis[exs[i]] = 1;
	}

	long long ret = -1;
	while(!pq.empty()){
		long long cdist; long long node; tie(cdist, node) = pq.top(); pq.pop();
		if(vis[node] == 2) continue;
		if(vis[node] == 0){
			vis[node] = 1;
			continue;
		}
		if(node == v){
			ret = cdist;
			break;
		}
		vis[node] = 2;
		for(auto u:adj[node]){
			if(vis[u.first] != 2) pq.push({cdist+u.second, u.first});
		}
	}

	return ret;
}

int main(){
	cin >> n >> m >> k;
	for(long long i=0;i<m;i++){
		long long a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	for(long long i=0;i<k;i++) cin >> exs[i];
	cout << dijkstra(0);
}


int travel_plan(int N, int M, int R[][2], int W[], int K, int E[]){
	n = N;
	m = M;
	k = K;
	for(int i=0;i<m;i++){
		int a = R[i][0], b = R[i][1], w = W[i];
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	for(int i=0;i<k;i++) exs[i] = E[i];
	return dijkstra(0);
}
