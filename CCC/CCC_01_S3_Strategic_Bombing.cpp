#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[26];
vector<bool> visited(26);
vector<pair<int, int>> roads;
pair<int, int> closed;

bool dfs(int v) {
    if (v == 1) return true;
    bool c = false;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!c && !visited[u] && make_pair(v, u) != closed && make_pair(u, v) != closed) {
            c = dfs(u);
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        string s; cin >> s;
        if (s == "**") break;
        int x = s[0]-65, y = s[1]-65;
        adj[x].push_back(y);
        adj[y].push_back(x);
        roads.push_back({x, y});
    }
    int sol = 0;
    for (auto road : roads) {
        visited.assign(26, false);
        closed = road;
        if (!dfs(0)) {
            sol++;
            char x = road.first+65, y = road.second+65;
            cout << x << y << "\n";
        }
    }
    cout << "There are " << sol << " disconnecting roads.\n";
}