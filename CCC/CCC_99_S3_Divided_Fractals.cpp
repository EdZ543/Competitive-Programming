#include <bits/stdc++.h>
using namespace std;

#define ll long long

void frac(vector<vector<string>> &grid, int n, int b, int t, int l, int r) {
    if (n == 0) return;
    int third = (r - l) / 3;
    for (int i = l + third; i < r - third; i++) {
        for (int j = t + third; j < b - third; j++) {
            grid[i][j] = "  ";
        }
    }
    for (int i = l; i < r; i += third) {
        for (int j = t; j < b; j += third) {
            frac(grid, n-1, j+third, j, i, i+third);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d; cin >> d;
    for (int i = 0; i < d; i++) {
        int n, b, t, l, r; cin >> n >> b >> t >> l >> r;
        vector<vector<string>> grid(pow(3, n), vector<string>(pow(3, n), "* "));
        frac(grid, n, grid.size(), 0, 0, grid.size());
        for (int i = t-1; i >= b-1; i--) {
            for (int j = l-1; j <= r-1; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}