#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c; cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        string row; cin >> row;
        for (int j = 0; j < c; j++) {
            grid[i][j] = row[j];
        }
    }
    int m; cin >> m;
    vector<char> moves(m);
    for (int i = 0; i < m; i++) cin >> moves[i];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vector<pair<int, int>> directions = {
                {-1, 0},
                {0, 1},
                {1, 0},
                {0, -1}
            };
            for (int k = 0; k < 4; k++) {
                int rpos = i;
                int cpos = j;
                int dir = k;
                bool good = true;
                for (auto move : moves) {
                    if (
                        rpos < 0 ||
                        rpos >= r ||
                        cpos < 0 ||
                        cpos >= c ||
                        grid[rpos][cpos] == 'X'
                    ) {
                        good = false;
                        break;
                    }
                    if (move == 'F') {
                        rpos += directions[dir].first;
                        cpos += directions[dir].second;
                    } else if (move == 'L') {
                        dir--;
                        if (dir < 0) dir = 3;
                    } else if (move == 'R') {
                        dir++;
                        if (dir > 3) dir = 0;
                    }
                }
                if (
                    rpos < 0 ||
                    rpos >= r ||
                    cpos < 0 ||
                    cpos >= c ||
                    grid[rpos][cpos] == 'X'
                ) {
                    good = false;
                }
                if (good) {
                    grid[rpos][cpos] = '*';
                }
            }
        }
    }
    for (auto row : grid) {
        for (auto cell : row) {
            cout << cell;
        }
        cout << "\n";
    }
}