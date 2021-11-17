#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

template<class T> T kruskal(int N, vector<pair<T,pair<int, int>>> ed) {
	sort(ed.begin(), ed.end());
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	for(auto a:ed) if (D.unite(a.second.first,a.second.second)) ans += a.first; 
	return ans;
}

int m;
pair<vector<int>, int> edges_adj[1001][1001];
vector<pair<int, pair<int, int>>> edge_list;
vector<pair<int, pair<int, int>>> edge_list_no_outside;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m;
	for(int i=1;i<=m;i++){
		int num_edges; cin >> num_edges;
		vector<pair<int, int>> edges(num_edges);
		for(int j=0;j<num_edges;j++) cin >> edges[j].first;
		for(int j=0;j<num_edges;j++) cin >> edges[j].second;
		edges.push_back(edges[0]);

		for(int j=0;j<num_edges;j++){
			edges_adj[edges[j].first][edges[j+1].first].first.push_back(i);
			edges_adj[edges[j].first][edges[j+1].first].second = edges[j].second;
			edges_adj[edges[j+1].first][edges[j].first].first.push_back(i);
			edges_adj[edges[j+1].first][edges[j].first].second = edges[j].second;
		}
	}	
	for(int i=0;i<1001;i++){
		for(int j=i+1;j<1001;j++){
			if(edges_adj[i][j].first.size() == 0) continue;
			int a, b, cost = edges_adj[i][j].second;
			if(edges_adj[i][j].first.size() == 1){
				a = 0;
				b = edges_adj[i][j].first[0];
			}else if(edges_adj[i][j].first.size() == 2){
				a = edges_adj[i][j].first[0];
				b = edges_adj[i][j].first[1];
			}
			edge_list.push_back({cost, {a, b}});
			if(a != 0 && b != 0) edge_list_no_outside.push_back({cost, {a, b}});
		}
	}
	cout << min(kruskal(m+1, edge_list), kruskal(m+1, edge_list_no_outside));
}