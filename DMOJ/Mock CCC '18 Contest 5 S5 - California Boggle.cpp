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
	cin.sync_with_stdio();
	cin.tie();

	int n; cin >> n;
	vector<string> grid;
	for(int i=0;i<n;i++){
		string row; cin >> row;
		grid.push_back(row);
	}

	int s = n*n*2, t = n*n*2+1;
	Dinic dinic(n*n*2+2, s, t); 

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dinic.add_edge(i*n+j, i*n+j+n*n, 1);
			if(grid[i][j] == 'C') dinic.add_edge(s, i*n+j, 1);
			if(grid[i][j] == 'I'){
				dinic.add_edge(i*n+j+n*n, t, 1);
				continue;
			}

			char next;
			if(grid[i][j] == 'C') next = 'A';
			else if(grid[i][j] == 'A') next = 'L';
			else if(grid[i][j] == 'L') next = 'I';

			for(int r=i-1;r<=i+1;r++){
				for(int c=j-1;c<=j+1;c++){
					if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != next) continue;
					dinic.add_edge(i*n+j+n*n, r*n+c, 1);
				}
			}
		}
	}

	cout << dinic.max_flow() << "\n";
}
