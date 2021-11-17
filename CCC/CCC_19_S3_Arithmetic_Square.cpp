#include <bits/stdc++.h>
using namespace std;
#define ll long long

int grid[3][3];
int x = 1e9+1;

bool solved() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == x) return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (grid[i][1]-grid[i][0] != grid[i][2]-grid[i][1]) return false;
    }

    for (int j = 0; j < 3; j++) {
        if (grid[1][j]-grid[0][j] != grid[2][j]-grid[1][j]) return false;
    }

    return true;
}

bool full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == x) return false;
        }
    }
    return true;
}

bool solve() {
    bool good = true;
    int changed[3][3] = {0};
    while (!solved() && good) {
        good = false;

        for (int i = 0; i < 3; i++) {
            int xs = 0;
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == x) {
                    xs++;
                }
            }
            if (xs == 1) {
                good = true;
                if (grid[i][0] == x) {
                    grid[i][0] = grid[i][1]-(grid[i][2]-grid[i][1]);
                    changed[i][0] = 1;
                } else if (grid[i][1] == x) {
                    grid[i][1] = (grid[i][0]+grid[i][2])/2;
                    changed[i][1] = 1;
                } else if (grid[i][2] == x) {
                    grid[i][2] = grid[i][1]+(grid[i][1]-grid[i][0]);
                    changed[i][2] = 1;
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            int xs = 0;
            for (int i = 0; i < 3; i++) {
                if (grid[i][j] == x) {
                    xs++;
                }
            }
            if (xs == 1) {
                good = true;
                if (grid[0][j] == x) {
                    grid[0][j] = grid[1][j]-(grid[2][j]-grid[1][j]);
                    changed[0][j] = 1;
                } else if (grid[1][j] == x) {
                    grid[1][j] = (grid[0][j]+grid[2][j])/2;
                    changed[1][j] = 1;
                } else if (grid[2][j] == x) {
                    grid[2][j] = grid[1][j]+(grid[1][j]-grid[0][j]);
                    changed[2][j] = 1;
                }
            }
        }
    }

    if (solved()) return true;
    if (full()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (changed[i][j]) grid[i][j] = x;
            }
        }
        return false;
    }


    for (int i = 0; i < 3; i++) {
        int idx = -1;
        bool fill = false;
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != x) {
                idx = j;
            } else {
                fill = true;
            }
        }

        if (idx != -1 && fill) {
            int num = grid[i][idx];
            if (idx == 0) {
                grid[i][1] = num; grid[i][2] = num;
                if (solve()) return true;
                grid[i][1] = num + 1; grid[i][2] = num + 2;
                if (solve()) return true;
                grid[i][1] = x; grid[i][2] = x;
            } else if (idx == 1) {
                grid[i][0] = num; grid[i][2] = num;
                if (solve()) return true;
                grid[i][0] = num - 1; grid[i][2] = num + 1;
                if (solve()) return true;
                grid[i][0] = x; grid[i][2] = x;
            } else {
                grid[i][1] = num; grid[i][0] = num;
                if (solve()) return true;
                grid[i][1] = num + 1; grid[i][0] = num + 2;
                if (solve()) return true;
                grid[i][1] = x; grid[i][0] = x;
            }
            break;
        }
    }

    for (int j = 0; j < 3; j++) {
        int idx = -1;
        bool fill = false;
        for (int i = 0; i < 3; i++) {
            if (grid[i][j] != x) {
                idx = i;
            } else {
                fill = true;
            }
        }

        if (idx != -1 && fill) {
            int num = grid[idx][j];
            if (idx == 0) {
                grid[1][j] = num; grid[2][j] = num;
                if (solve()) return true;
                grid[1][j] = num + 1; grid[2][j] = num + 2;
                if (solve()) return true;
                grid[1][j] = x; grid[2][j] = x;
            } else if (idx == 1) {
                grid[0][j] = num; grid[2][j] = num;
                if (solve()) return true;
                grid[0][j] = num - 1; grid[2][j] = num + 1;
                if (solve()) return true;
                grid[0][j] = x; grid[2][j] = x;
            } else {
                grid[1][j] = num; grid[0][j] = num;
                if (solve()) return true;
                grid[1][j] = num + 1; grid[0][j] = num + 2;
                if (solve()) return true;
                grid[1][j] = x; grid[0][j] = x;
            }
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (changed[i][j]) grid[i][j] = x;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int xs = 0, num = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s; cin >> s;
            if (s == "X") {
                grid[i][j] = x;
                xs++;
            } else {
                grid[i][j] = stoi(s);
                num = stoi(s);
            }
        }
    }    

    if (xs >= 8) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = num;
            }
        }
    } else {
        solve();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}