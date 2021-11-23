#include <bits/stdc++.h>
using namespace std;

long long n, m, d;
vector<vector<long long>> edges;
vector<long long> e;

struct DSU{
	void init(long long n){
		e = vector<long long>(n+1, -1);
	}
	long long get(long long x){
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}
	bool unite(long long x, long long y){
		x = get(x);
		y = get(y);
		if(x == y) return false;
		if(e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int kruskals(long long n, vector<vector<long long>> edges){
	sort(edges.begin(), edges.end());
	DSU dsu;
	dsu.init(n);
	long long ee = 0, ret = 0, maxc = 0, i = 0;
	for(i=0;i<edges.size();i++){
		if(ee == n-1) break;
		auto edge = edges[i];
		if(dsu.unite(edge[2], edge[3])){
			ee++;
			maxc = edge[0];
			if(edge[1]){
				ret++;
			}
		}
	}

	if(edges[i-1][1]){
		dsu.init(n);
		for(auto edge:edges){
			if(dsu.get(edge[2]) != dsu.get(edge[3])){
				if(edge[0] < maxc || (edge[0] == maxc && !edge[1])){
					dsu.unite(edge[2], edge[3]);
				}else if(!edge[1] && edge[0] <= d){
					return ret-1;
				}
			}
		}
	}
	return ret;
}

int main(){
	cin >> n >> m >> d;
	for(long long i=0;i<m;i++){
		long long a, b, c; cin >> a >> b >> c;
		edges.push_back({c, i >= n-1, a, b});
	}
	cout << kruskals(n, edges);
}