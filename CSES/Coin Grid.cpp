#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int a, b;
	long long flow = 0, cap;
	int res;
	Edge(int a, int b, long long cap, int res):a(a), b(b), cap(cap), res(res){}
};

struct Dinic{
	const long long INF = LLONG_MAX;
	int n, s, t;
	vector<Edge> edges;
	vector<vector<int>> adj;
	vector<int> level;
	vector<int> next;

	Dinic(int n, int s, int t):n(n), s(s), t(t){
		adj.resize(n);
		level.resize(n);	
		next.resize(n);
	}

	void add_edge(int a, int b, long long cap){
		int edge1 = edges.size(), edge2 = edges.size()+1;
		edges.emplace_back(a, b, cap, edge2);
		edges.emplace_back(b, a, 0, edge1);
		adj[a].push_back(edge1);
		adj[b].push_back(edge2);
	}

	bool bfs(){
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		q.push(s);
		level[s] = 0;
		while(!q.empty()){
			int cur = q.front();
		   	q.pop();
			for(auto id:adj[cur]){
				Edge edge = edges[id];
				long long rcap = edge.cap-edge.flow;
				if(rcap > 0 && level[edge.b] == -1){
					level[edge.b] = level[cur]+1;
					q.push(edge.b);
				}
			}
		}	
		return level[t] != -1;
	}

	long long dfs(int v, vector<int> next, long long flow){
		if(v == t) return flow;
		int num_edges = adj[v].size();
		for(;next[v]<num_edges;next[v]++){
			int id = adj[v][next[v]];
			Edge edge = edges[id];
			long long rcap = edge.cap-edge.flow;
			if(rcap > 0 && level[edge.b] == level[v]+1){
				long long bn = dfs(edge.b, next, min(flow, rcap));
				if(bn > 0){
					edges[id].flow += bn;
					edges[edge.res].flow -= bn;			
					return bn;
				}
			}
		}
		return 0;
	}

	long long max_flow(){
		long long ret = 0;
		while(bfs()){
			fill(next.begin(), next.end(), 0);
			for(long long flow=dfs(s, next, INF);flow!=0;flow=dfs(s, next, INF)) ret += flow;
		}
		return ret;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int s = 0, t = 2*n+1;
	Dinic dinic(2*n+2, s, t);
	for(int i=1;i<=n;i++){
		dinic.add_edge(s, i, 1);
		dinic.add_edge(n+i, t, 1);
	}

	for(int r=1;r<=n;r++){
		string row; cin >> row;
		for(int c=1;c<=n;c++) if(row[c-1] == 'o') dinic.add_edge(r, n+c, LLONG_MAX);
	}

	cout << dinic.max_flow() << "\n";
	dinic.bfs();
	for(int i=1;i<=n;i++){
		if(dinic.level[i] < 0) cout << 1 << " " << i << "\n";
		if(dinic.level[i+n] >= 0) cout << 2 << " " << i << "\n";
	}
}
