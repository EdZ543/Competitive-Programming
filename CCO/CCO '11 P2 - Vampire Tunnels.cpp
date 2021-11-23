#include <bits/stdc++.h>
using namespace std;

struct triple{
	int a, b, c;
};

bool cmp(triple a, triple b){
	return a.a > b.a;
}

int s, n, e;
vector<vector<triple>> adj;
vector<vector<int>> dp;

void dijkstra(int src){
	using T = triple; priority_queue<T, vector<T>, std::function<bool(T, T)>> pq(cmp);
	dp[0][0] = 0;
	pq.push({0, 0, src});

	while(!pq.empty()){
		int cdist = pq.top().a, clight = pq.top().b, cnode = pq.top().c;	pq.pop();
		if(cdist != dp[cnode][clight]) continue;
		for(auto u:adj[cnode]){
			int ndist = cdist+u.b, nlight = u.c?clight+u.b:clight, nnode = u.a;
			if(nlight <= s && ndist < dp[nnode][nlight]){
				pq.push({dp[nnode][nlight] = ndist, nlight, nnode});
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>s>>n>>e;
	adj.resize(n);
	dp.resize(n, vector<int>(s+1, INT_MAX));
	for(int i=0;i<e;i++){
		int a, b, c, d; cin>>a>>b>>c>>d;
		adj[a].push_back({b, c, d});
		adj[b].push_back({a, c, d});
	}

	dijkstra(0);

	int sol = INT_MAX;
	for(int i=0;i<=s;i++) sol = min(sol, dp[n-1][i]);
	
	sol == INT_MAX?cout<<-1:cout<<sol;
}
