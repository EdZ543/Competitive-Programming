#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> adj_list[100000];
vector<bool> visited;
vector<int> x, y;
int n, m;

vector<int> dfs(int v, vector<int> corners) {
    corners[0] = min(corners[0], x[v]);
    corners[1] = max(corners[1], x[v]);
    corners[2] = min(corners[2], y[v]);
    corners[3] = max(corners[3], y[v]);
    visited[v] = true;
    for (auto u : adj_list[v]) {
        if (!visited[u]) {
            corners = dfs(u, corners);
        }
    }
    return corners;
}

int main(){
    setIO("fenceplan");
    
    cin >> n >> m;
    x.assign(n, 0);
    y.assign(n, 0);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int sol = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            auto corners = dfs(i, {INT_MAX, INT_MIN, INT_MAX, INT_MIN});
            int w = corners[1] - corners[0];
            int l = corners[3] - corners[2];
            int p = 2 * (w + l);
            sol = min(sol, p);
        }
    }
    cout << sol;
}