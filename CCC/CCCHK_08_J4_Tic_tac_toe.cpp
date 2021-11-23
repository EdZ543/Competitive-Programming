#include <bits/stdc++.h>
using namespace std;

bool isValid(string game) {
    int numX = 0;
    int numO = 0;
    vector<vector<int>> winChecks2 = {
        {0, 1, 2, game[0] == game[1] && game[1] == game[2] && game[0] != '.'},
        {3, 4, 5, game[3] == game[4] && game[4] == game[5] && game[3] != '.'},
        {6, 7, 8, game[6] == game[7] && game[7] == game[8] && game[6] != '.'},
        {0, 3, 6, game[0] == game[3] && game[3] == game[6] && game[0] != '.'},
        {1, 4, 7, game[1] == game[4] && game[4] == game[7] && game[1] != '.'},
        {2, 5, 8, game[2] == game[5] && game[5] == game[8] && game[2] != '.'},
        {0, 4, 8, game[0] == game[4] && game[4] == game[8] && game[0] != '.'},
        {2, 4, 6, game[2] == game[4] && game[4] == game[6] && game[2] != '.'},
    };

    for (char c : game) {
        if (c == 'X') {
            numX++;
        } else if (c == 'O') {
            numO++;
        }
    }

    for (vector<int> winCheck : winChecks2) {
        if (winCheck[3]) {
            if (game[winCheck[0]] == 'X') {
                if (numX - numO != 1) {
                    return false;
                }
            } else if (game[winCheck[0]] == 'O') {
                if (numO - numX != 0) {
                    return false;
                }
            }
        } else {
            if (numX - numO > 1 || numO - numX > 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string game;
        cin >> game;
        cout << (isValid(game) ? "yes\n" : "no\n");
    }
}