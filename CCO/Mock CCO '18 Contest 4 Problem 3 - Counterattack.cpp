#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2e5+1;

long long n, m;
vector<pair<long long, long long>> adj[MAXN];
long long dist[MAXN][2];

void dijkstra(long long src){
	for(long long i=1;i<=n;i++) for(long long j=0;j<2;j++) dist[i][j] = INT_MAX;

	using T = pair<long long, long long>; priority_queue<T, vector<T>, greater<T>> pq;
	dist[src][0] = 0;
	pq.push({0, src});

	while(!pq.empty()){
		long long cdist, cnode; tie(cdist, cnode) = pq.top(); pq.pop();
		if(cdist != dist[cnode][0] && cdist != dist[cnode][1]) continue;

		for(auto u:adj[cnode]){
			long long ndist = cdist+u.second, nnode = u.first;
			if(ndist < dist[nnode][0]){
				dist[nnode][1] = dist[nnode][0];
				pq.push({dist[nnode][0] = ndist, nnode});
			}else if(ndist > dist[nnode][0] && ndist < dist[nnode][1]){
				pq.push({dist[nnode][1] = ndist, nnode});
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(long long i=0;i<m;i++){
		long long a, b, c; cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	dijkstra(1);
	
	if(dist[n][1] == INT_MAX) cout<<-1<<"\n";
	else cout<<dist[n][1]<<"\n";
}
