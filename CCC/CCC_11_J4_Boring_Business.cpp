#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> grid(201, vector<bool>(401, false));
vector<vector<int>> drilled = {
    {0, -1},
    {0, -2},
    {0, -3},
    {1, -3},
    {1, -3},
    {3, -3},
    {3, -4},
    {3, -5},
    {4, -5},
    {5, -5},
    {5, -4},
    {5, -3},
    {6, -3},
    {7, -3},
    {7, -4},
    {7, -5},
    {7, -6},
    {7, -7},
    {6, -7},
    {5, -7},
    {4, -7},
    {3, -7},
    {2, -7},
    {1, -7},
    {0, -7},
    {-1, -7},
    {-1, -6},
    {-1, -5},
};

vector<int> toReal(vector<int> pos) {
    return {pos[0] + 200, abs(pos[1]) - 1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (vector<int> pos : drilled) {
        vector<int> realPos = toReal(pos);
        grid[realPos[1]][realPos[0]] = true;
    }
	
    vector<int> pos = {-1, -5};

    while (true) {
        char direction;
        int length;
        cin >> direction >> length;
        string safety = "safe";

        if (direction == 'q') {
            break;
        }

        for (int i = 0; i < length; i++) {
            if (direction == 'u') {
                pos[1]++;
            } else if (direction == 'd') {
                pos[1]--;
            } else if (direction == 'l') {
                pos[0]--;
            } else if (direction == 'r') {
                pos[0]++;
            }

            vector<int> realPos = toReal(pos);
            if (grid[realPos[1]][realPos[0]] == true) {
                safety = "DANGER";
            } else {
                grid[realPos[1]][realPos[0]] = true;
            }
        }

        cout << pos[0] << " " << pos[1] << " " << safety << "\n";

        if (safety == "DANGER") {
            break;
        }
    }
}