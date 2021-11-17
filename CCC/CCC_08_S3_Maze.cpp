#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) cin >> grid[i];

        vector<pair<int, int>> adj[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i != 0 && grid[i-1][j] != '*' && (grid[i][j] == '+' || grid[i][j] == '|')) {
                    adj[i][j].push_back({i-1, j});
                }
                if (i != r - 1 && grid[i+1][j] != '*' && (grid[i][j] == '+' || grid[i][j] == '|')) {
                    adj[i][j].push_back({i+1, j});
                }
                if (j != 0 && grid[i][j-1] != '*' && (grid[i][j] == '+' || grid[i][j] == '-')) {
                    adj[i][j].push_back({i, j-1});
                }
                if (j != c - 1 && grid[i][j+1] != '*' && (grid[i][j] == '+' || grid[i][j] == '-')) {
                    adj[i][j].push_back({i, j+1});
                }
            }
        }

        pair<int, int> startNode = {0, 0};
        pair<int, int> targetNode = {r-1, c-1};
        vector<vector<bool>> visited(r, vector<bool>(c));
        queue<pair<int, int>> bfsQueue;
        bool good = false;
        vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>>(c));

        visited[startNode.first][startNode.second] = true;
        bfsQueue.push(startNode);

        while (!bfsQueue.empty()) {
            pair<int, int> currentNode = bfsQueue.front();
            if (currentNode == targetNode) {
                good = true;
                break;
            }
            bfsQueue.pop();

            for (auto u : adj[currentNode.first][currentNode.second]) {
                if (!visited[u.first][u.second]) {
                    visited[u.first][u.second] = true;
                    bfsQueue.push(u);
                    parent[u.first][u.second] = currentNode;
                }
            }
        }

        if (!good) {
            cout << -1 << "\n";
        } else {
            int sol = 1;
            while (targetNode != startNode) {
                targetNode = parent[targetNode.first][targetNode.second];
                sol++;
            }
            cout << sol << "\n";
        }
    }
}