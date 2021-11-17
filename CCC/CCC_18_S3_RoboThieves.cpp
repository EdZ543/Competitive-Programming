#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
vector<pair<int, int>> adj[100][100];

int bfs(pair<int, int> startNode, pair<int, int> target) {
    queue<pair<int, int>> bfsQueue;
    vector<vector<bool>> visited(100, vector<bool>(100, false));
    pair<int, int> parent[100][100];

    visited[startNode.first][startNode.second] = true;
    bfsQueue.push(startNode);

    bool good = false;
    while (!bfsQueue.empty()) {
        pair<int, int> currentNode = bfsQueue.front();
        if (currentNode == target) {
            good = true;
            break;
        }
        bfsQueue.pop();

        for (auto neighbour: adj[currentNode.first][currentNode.second]) {
            if (!visited[neighbour.first][neighbour.second]) {
                parent[neighbour.first][neighbour.second] = currentNode;
                visited[neighbour.first][neighbour.second] = true;
                bfsQueue.push(neighbour);
            }
        }
    }

    if (!good) {
        return -1;
    } else {
        int dist = 0;
        while (target != startNode) {
            target = parent[target.first][target.second];
            dist++;
        }
        return dist;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    pair<int, int> startNode;
    bool bruh = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                startNode = {i, j};
            } else if (grid[i][j] == 'C') {
                vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
                for (auto direction : directions) {
                    int checki = i, checkj = j;
                    while (checki > -1 && checki < n && checkj > -1 && checkj < m && grid[checki][checkj] != 'W') {
                        if (grid[checki][checkj] == '.') grid[checki][checkj] = 'E';
                        if (grid[checki][checkj] == 'S') bruh = true;
                        checki += direction.first;
                        checkj += direction.second;
                    }
                }
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' || grid[i][j] == 'S') {
                vector<pair<int, int>> steps = {{i-1, j}, {i, j+1}, {i+1, j}, {i, j-1}};
                for (auto step : steps) {
                    if (step.first > -1 && step.first < n && step.second > -1 && step.second < m) {
                        char cell = grid[step.first][step.second];
                        if (cell == '.' || cell == 'S') {
                            adj[i][j].push_back({step.first, step.second});
                        } else if (cell == 'U' || cell == 'D' || cell == 'L' || cell == 'R') {
                            int ci = step.first, cj = step.second;
                            vector<vector<bool>> visited(100, vector<bool>(100));
                            bool good = false;
                            while (true) {
                                if (ci <= -1 || ci >= n || cj <= -1 || cj >= m || visited[ci][cj]) {
                                    break;
                                }
                                if (grid[ci][cj] == 'W' || grid[ci][cj] == 'E') {
                                    break;
                                }
                                visited[ci][cj] = true;
                                if (grid[ci][cj] == '.' || grid[ci][cj] == 'S') {
                                    good = true;
                                    break;
                                } else if (grid[ci][cj] == 'U') {
                                    ci--;
                                } else if (grid[ci][cj] == 'D') {
                                    ci++;
                                } else if (grid[ci][cj] == 'L') {
                                    cj--;
                                } else if (grid[ci][cj] == 'R') {
                                    cj++;
                                }
                            }
                            if (good) {
                                adj[i][j].push_back({ci, cj});
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (bruh) {
                    cout << -1 << "\n";
                } else {
                    cout << bfs(startNode, {i, j}) << "\n";
                }
            } else if (grid[i][j] == 'E') {
                cout << -1 << "\n";
            }
        }
    }
}