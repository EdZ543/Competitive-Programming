#include <bits/stdc++.h>
using namespace std;

#define ll long long

int w, r, c;
vector<pair<int, int>> adj[25][25];
bool visited[25][25];

int dfs(pair<int, int> v) {
    int area = 1;
    visited[v.first][v.second] = true;
    for (auto u : adj[v.first][v.second]) {
        if (!visited[u.first][u.second]) {
            area += dfs(u);
        }
    }
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> w >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) cin >> grid[i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != 'I') {
                if (i != 0 && grid[i-1][j] != 'I') {
                    adj[i][j].push_back({i-1, j});
                }
                if (i != r - 1 && grid[i+1][j] != 'I') {
                    adj[i][j].push_back({i+1, j});
                }
                if (j != 0 && grid[i][j-1] != 'I') {
                    adj[i][j].push_back({i, j-1});
                }
                if (j != c - 1 && grid[i][j+1] != 'I') {
                    adj[i][j].push_back({i, j+1});
                } 
            }
        }
    }

    vector<int> areas;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && grid[i][j] != 'I') {
                areas.push_back(dfs({i, j}));
            }
        }
    }

    sort(areas.begin(), areas.end());
    int rooms = 0;
    for (int i = areas.size()-1; i >= 0; i--) {
        if (w < areas[i]) {
            break;
        } else {
            w -= areas[i];
            rooms++;
        }
    }
    cout << rooms << (rooms == 1 ? " room, " : " rooms, ") << w << " square metre(s) left over\n";
}