#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, m, a, b;
char c;
string s;
vector<int> adj[100001];
vector<bool> visited(100001);
vector<int> comps(100001);
int cn = 0;

void dfs(int v) {
    if (s[v] != c) return;
    comps[v] = cn;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    setIO("milkvisits");
    cin >> n >> m >> s;
    s = " "+s;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cn++;
            c = s[i];
            dfs(i);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (comps[a] == comps[b]) {
            if (s[a] == c) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else if (comps[a] != comps[b]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}