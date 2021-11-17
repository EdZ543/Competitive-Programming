#include <bits/stdc++.h>
using namespace std;

#define ll long long

void print(vector<vector<int>> grid) {
    for (auto row : grid) {
        for (auto num : row) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}

void rotate(vector<vector<int>>& grid) {
    vector<vector<int>> rotated(grid.size(), vector<int>(grid.size()));
    int r = 0, c = grid.size()-1;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            rotated[r][c] = grid[i][j];
            r++;
            if (r >= grid.size()) {
                r = 0;
                c--;
            }
        }
    }
    grid = rotated;
}

bool valid(vector<vector<int>> grid) {
    vector<vector<int>> rowSorted = grid;
    for (int i = 0; i < grid.size(); i++) {
        sort(begin(rowSorted[i]), end(rowSorted[i]));
        bool same = equal(begin(grid[i]), end(grid[i]), begin(rowSorted[i]));
        if (!same) return false;
    }
    rotate(rowSorted);
    rotate(grid); 
    for (int i = 0; i < grid.size(); i++) {
        sort(begin(rowSorted[i]), end(rowSorted[i]), greater<int>());
        bool same = equal(begin(grid[i]), end(grid[i]), begin(rowSorted[i]));
        if (!same) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    while (true) {
        if (valid(grid)) {
            print(grid);
            break;
        }
        rotate(grid);
    }
}