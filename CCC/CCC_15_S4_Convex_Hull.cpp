#include <bits/stdc++.h>
using namespace std;

int k, n, m, a, b;
vector<vector<int>> adj[2001];
int dist[2001][201];
bool visited[2001];

void dijkstra(){
	for(int i=0;i<2001;i++){
		for(int j=0;j<201;j++) dist[i][j] = 1061109567;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[a][0] = 0;
	pq.push({0, a});
	visited[a] = true;

	while(!pq.empty()){
		int node = pq.top().second;
		visited[node] = false;
		pq.pop();
		for(vector<int> u:adj[node]){
			for(int j=0;j+u[2]<k;j++){
				int alt = dist[node][j]+u[1];
				if(alt < dist[u[0]][j+u[2]]){
					dist[u[0]][j+u[2]] = alt;
					if(!visited[u[0]]){
						visited[u[0]] = true;
						pq.push({alt, u[0]});
					}
				}
			}	
		}
	}
}

int main(){
	cin >> k >> n >> m;
	for(int i=0;i<m;i++){
		int ai, bi, ti, hi; cin >> ai >> bi >> ti >> hi;
		adj[ai].push_back({bi, ti, hi});
		adj[bi].push_back({ai, ti, hi});
	}
	cin >> a >> b;
	dijkstra();
	int sol = INT_MAX;
	for(int i=0;i<k;i++) sol = min(sol, dist[b][i]);
	sol == 1061109567 ? cout << -1 : cout << sol;
}