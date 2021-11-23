#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c; cin >> r >> c;
    int grid[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    int sol = 0;
    pair<int, int> center;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int size = 0;
            pair<int, int> top = {i-1, j};
            pair<int, int> bottom = {i+1, j};
            pair<int, int> left = {i, j-1};
            pair<int, int> right = {i, j+1};
            while (true) {
                if (top.first < 0 ||
                    bottom.first >= r ||
                    left.second < 0 ||
                    right.second >= c ||
                    grid[top.first][top.second] != grid[bottom.first][bottom.second] ||
                    grid[top.first][top.second] != grid[left.first][left.second] ||
                    grid[top.first][top.second] != grid[right.first][right.second]) {
                        if (size > sol) {
                            sol = size;
                            center = {i+1, j+1};
                        }
                        break;
                    }

                top.first--;
                bottom.first++;
                left.second--;
                right.second++;
                size++;
            }
        }
    }
    cout << sol << " " << center.first << " " << center.second << "\n";
}