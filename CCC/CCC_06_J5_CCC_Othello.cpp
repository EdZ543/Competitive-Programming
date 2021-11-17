#include <bits/stdc++.h>
using namespace std;

#define ll long long

void draw(vector<vector<char>> board) {
    for (auto row : board) {
        for (auto cell : row) {
            if (cell == ' ') {
                cout << "🟪";
            } else if (cell == 'b') {
                cout << "⬛";
            } else if (cell == 'w') {
                cout << "⬜";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<char>> board;
    
    vector<vector<char>> configA = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'w', 'b', ' ', ' ', ' '},
        {' ', ' ', ' ', 'b', 'w', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    vector<vector<char>> configB = {
        {'b', ' ', ' ', ' ', ' ', ' ', ' ', 'w'},
        {' ', 'b', ' ', ' ', ' ', ' ', 'w', ' '},
        {' ', ' ', 'b', ' ', ' ', 'w', ' ', ' '},
        {' ', ' ', ' ', 'b', 'w', ' ', ' ', ' '},
        {' ', ' ', ' ', 'w', 'b', ' ', ' ', ' '},
        {' ', ' ', 'w', ' ', ' ', 'b', ' ', ' '},
        {' ', 'w', ' ', ' ', ' ', ' ', 'b', ' '},
        {'w', ' ', ' ', ' ', ' ', ' ', ' ', 'b'}
    };

    vector<vector<char>> configC = {
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '},
        {' ', ' ', 'b', 'b', 'w', 'w', ' ', ' '}
    };

    string config; int N;
    cin >> config >> N;

    if (config == "a") {
        board = configA;
    } else if (config == "b") {
        board = configB;
    } else if (config == "c") {
        board = configC;
    }

    char player = 'b';
    vector<pair<int, int>> directions = {
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1}
    };

    for (int i = 0; i < N; i++) {
        int R, C; cin >> R >> C;
        R--; C--;

        board[R][C] = player;

        for (auto direction : directions) {
            vector<vector<char>> newBoard = board;
            int r = R, c = C;
            bool good = false;

            while (true) {
                r += direction.first;
                c += direction.second;
                if (r < 0 || r > 7 || c < 0 || c > 8 || board[r][c] == ' ') {
                    break;
                } else if (board[r][c] == player) {
                    good = true;
                    break;
                } else {
                    newBoard[r][c] = player;
                }
            }

            if (good) board = newBoard;
        }

        player = player == 'b' ? 'w' : 'b';

        // draw(board);
    }

    int b = 0, w = 0;
    for (auto row : board) {
        for (auto cell : row) {
            if (cell == 'b') {
                b++;
            } else if (cell == 'w') {
                w++;
            }
        }
    }
    cout << b << " " << w;
}