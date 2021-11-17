#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool searched[1001][1001];
vector<vector<pair<int, int>>> vals(1000001);

string possible(pair<int, int> lastCell) {
    queue<pair<int, int>> q;
    q.push(lastCell);
    while (q.size() > 0) {
        pair<int, int> cell = q.front();
        q.pop();
        vector<pair<int, int>> neighbors = vals[cell.first * cell.second];
        for (auto neighbor : neighbors) {
            if (neighbor.first == 1 && neighbor.second == 1) {
                return "yes";
            } else if (!searched[neighbor.first][neighbor.second]) {
                searched[neighbor.first][neighbor.second] = true;
                q.push(neighbor);
            }
        }
    }
    return "no";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N; cin >> M >> N;
    pair<int, int> lastCell;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int val; cin >> val;
            vals[val].push_back({i, j});
            if (i == M && j == N) {
                lastCell = {i, j};
            }
        }
    }
    cout << possible(lastCell);
}