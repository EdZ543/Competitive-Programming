#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> friends[10000];
vector<bool> visited(10000);
int target, dist;
bool found;

void dfs(int node) {
    if (node == target) {
        found = true;
        return;
    } else {
        dist++;
    }
    visited[node] = true;
    for (auto u : friends[node]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        friends[x].push_back(y);
    }
    while (true) {
        int x, y; cin >> x >> y;
        if (x == 0 && y == 0) break;
        visited.assign(10000, false);
        target = y;
        dist = -1;
        found = false;
        dfs(x);
        !found ? cout << "No\n" : cout << "Yes " << dist << "\n";
    }
}