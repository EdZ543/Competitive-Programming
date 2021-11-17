#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N, M;
    cin >> N >> M;
    vector<vector<bool>> board(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (
                    i == x ||
                    j == y ||
                    abs(i - x) == abs(j - y)
                ) {
                    board[i][j] = true;
                }
            }
        }
    }
    int total = 0;
    for (vector<bool> row : board) {
        for (bool cell : row) {
            if (cell == false) {
                total++;
            }
        }
    }
    cout << total;
}