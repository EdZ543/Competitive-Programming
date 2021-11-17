#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int n, q;
int value[MAXN];
vector<int> adj[MAXN];
vector<int> ind, si, val;
vector<bool> visited(MAXN, false);
int cnt = 1;

struct segtree{
	int size;
	vector<long long> sums;

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2*size, 0);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx-lx == 1){
			if(lx < a.size()){
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		sums[x] = sums[2*x+1]+sums[2*x+2];
	}

	void build(vector<int> &a){
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx == 1){
			sums[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i < m) set(i, v, 2*x+1, lx, m);
		else set(i, v, 2*x+2, m, rx);
		sums[x] = sums[2*x+1]+sums[2*x+2];
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
	}

	long long sum(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return sums[x];
		int m = (lx+rx)/2;
		long long s1 = sum(l, r, 2*x+1, lx, m);
		long long s2 = sum(l, r, 2*x+2, m, rx);
		return s1+s2;
	}

	long long sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
};

int dfs(int v){
	visited[v] = true;
	ind[v] = cnt++;
	int subsize = 1;
	for(auto u:adj[v]) if(!visited[u]) subsize += dfs(u);
	si[ind[v]] = subsize;
	val[ind[v]] = value[v];
	return subsize;
}

int main(){
	cin >> n >> q;
	ind.resize(n+1);
	si.resize(n+1);
	val.resize(n+1);
	for(int i=1;i<=n;i++) cin >> value[i];	
	for(int i=0;i<n-1;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	segtree st;
	st.init(n+1);
	dfs(1);
	st.build(val);

	while(q--){
		int op; cin >> op;
		if(op == 1){
			int s, x; cin >> s >> x;
			st.set(ind[s], x);
		}else{
			int s; cin >> s;
			cout << st.sum(ind[s], ind[s]+si[ind[s]]) << "\n";
		}
	}
}
