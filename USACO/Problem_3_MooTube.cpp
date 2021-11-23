#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<pair<int, int>> adj[5001];
vector<bool> visited(5001);
int k, v, sol;

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u.first] && u.second >= k) {
            sol++;
            dfs(u.first);
        }
    }
}

int main(){
    setIO("mootube");
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b, r; cin >> a >> b >> r;
        adj[a].push_back({b, r});
        adj[b].push_back({a, r});
    }
    for (int i = 0; i < q; i++) {
        cin >> k >> v;
        sol = 0;
        visited.assign(5001, false);
        dfs(v);
        cout << sol << "\n";
    }
}