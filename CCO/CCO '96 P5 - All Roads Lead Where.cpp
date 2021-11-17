#include <bits/stdc++.h>
using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }

#include <bits/stdc++.h>
using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }

	int depth(int v){
		return height[v];
	}

	int dist(int a, int b){
		return depth(a)+depth(b)-2*depth(lca(a, b));
	}
};

int m, n;
vector<vector<int>> adj(26);
int par[26];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>m>>n;
	for(int i=0;i<m;i++){
		string a, b; cin>>a>>b;
		int ai = a[0]-'A', bi = b[0]-'A';
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
		par[bi] = ai;
	}

	LCA lca(adj, 17);

	while(n--){
		string a, b; cin>>a>>b;
		int ai = a[0]-'A', bi = b[0]-'A';
		int ci = lca.lca(ai, bi);
		string atoc = "";
		int ind = ai;
		while(ind != ci){
			char ch = 'A'+ind;
			atoc += ch;
			ind = par[ind];
		}
		string ctob = "";
		int bind = bi;
		while(bind != ci){
			char ch = 'A'+bind;
			ctob = ch+ctob;
			bind = par[bind];
		}
		char ch = 'A'+ci;
		cout<<atoc+ch+ctob<<"\n";
	}
}
	int depth(int v){
		return height[v];
	}

	int dist(int a, int b){
		return depth(a)+depth(b)-2*depth(lca(a, b));
	}
};

int m, n;
vector<vector<int>> adj(26);
int par[26];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>m>>n;
	for(int i=0;i<m;i++){
		string a, b; cin>>a>>b;
		int ai = a[0]-'A', bi = b[0]-'A';
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
		par[bi] = ai;
	}

	LCA lca(adj, 17);

	while(n--){
		string a, b; cin>>a>>b;
		int ai = a[0]-'A', bi = b[0]-'A';
		int ci = lca.lca(ai, bi);
		string atoc = "";
		int ind = ai;
		while(ind != ci){
			char ch = 'A'+ind;
			atoc += ch;
			ind = par[ind];
		}
		string ctob = "";
		int bind = bi;
		while(bind != ci){
			char ch = 'A'+bind;
			ctob = ch+ctob;
			bind = par[bind];
		}
		char ch = 'A'+ci;
		cout<<atoc+ch+ctob<<"\n";
	}
}
