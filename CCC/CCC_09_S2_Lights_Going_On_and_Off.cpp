#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, L; cin >> R >> L;
    vector<vector<int>> rows(R, vector<int>(L));
    for (int r = 0; r < R; r++) {
        for (int l = 0; l < L; l++) {
            cin >> rows[r][l];
        }
    }
    vector<vector<int>> patterns = {rows[R-1]};
    for (int i = R - 1; i > 0; i--) {
        vector<vector<int>> rowsCopy = rows;
        for (int j = i; j < R; j++) {
            for (int k = 0; k < L; k++) {
                int current = rowsCopy[j][k];
                int above = rowsCopy[j-1][k];
                if (current == above) {
                    rowsCopy[j][k] = 0;
                } else {
                    rowsCopy[j][k] = 1;
                }
            }
        }
        if (find(begin(patterns), end(patterns), rowsCopy[R-1]) == end(patterns)) {
            patterns.push_back(rowsCopy[R-1]);
        }
    }
    cout << patterns.size();
}