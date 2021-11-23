#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> e;
	void init(int n){
		e = vector<int>(n, -1);
	}
	int get(int x){
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}
	bool unite(int x, int y){
		x = get(x);
		y = get(y);
		if(x == y) return false;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};


int n, m, q;
typedef vector<int> Edge;
multiset<Edge, std::greater<Edge>> edges;
vector<Edge> edgeList;
vector<vector<pair<int, int>>> adj(1001);
bool visited[5001];

void kruskal(int n, multiset<Edge, std::greater<Edge>> edges){
	vector<vector<pair<int, int>>> mst(1001);
	DSU d;
	d.init(n+1);
	for(auto edge:edges){
		if(d.unite(edge[2], edge[3])){
			mst[edge[2]].push_back({edge[0], edge[3]});
			mst[edge[3]].push_back({edge[0], edge[2]});	
		}
	}
	adj = mst;
}

void update(int m, int x){
	edges.erase(edgeList[m-1]);
	edgeList[m-1][0] = x;
	edges.insert(edgeList[m-1]);
	kruskal(n, edges);
}

bool query(int a, int b, int w){
	if(a == b) return true;

	visited[a] = true;
	for(auto u:adj[a]){
		if(!visited[u.second] && u.first >= w){
			if(query(u.second, b, w)) return true;
		}
	}

	return false;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u, v, z; cin >> u >> v >> z;
		edges.insert({z, i, u, v});
		edgeList.push_back({z, i, u, v});
	}	
	kruskal(n, edges);
	cin >> q;
	for(int i=0;i<q;i++){
		int type; cin >> type;
		if(type == 1){
			int m, x; cin >> m >> x;
			update(m, x);
		}else{
			int a, b, w; cin >> a >> b >> w;
			memset(visited, false, sizeof(visited));
			cout << query(a, b, w) << '\n';
		}
	}
}
