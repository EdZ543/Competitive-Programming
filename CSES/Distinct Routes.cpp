#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int a, b;
	long long flow = 0, cap;
	int res;
	Edge(int a, int b, long long cap, int res):a(a), b(b), cap(cap), res(res){}
};

vector<vector<int>> paths;

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

	vector<int> pdfs(int v){
		if(v == t) return {v};
		for(auto id:adj[v]){
			Edge edge = edges[id];
			if(edge.flow == 1){
				edges[id].flow = 0;
				vector<int> path = pdfs(edge.b);
				if(!path.empty()){
					path.insert(path.begin(), v);
					return path;
				}
			}
		}
		return {};
	}

	vector<vector<int>> paths(){
		vector<vector<int>> ret;
		for(vector<int> path=pdfs(s);!path.empty();path=pdfs(s)) ret.push_back(path);
		return ret;	
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	Dinic dinic(n+1, 1, n);
	for(int i=0;i<m;i++){
		int a, b; cin >> a >> b;
		dinic.add_edge(a, b, 1);
	}

	cout << dinic.max_flow() << "\n";
	vector<vector<int>> paths = dinic.paths();
	for(auto path:paths){
		cout << path.size() << "\n";
		for(auto room:path) cout << room << " ";
		cout << "\n";
	}
}
