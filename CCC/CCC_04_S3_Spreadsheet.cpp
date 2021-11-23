#include <bits/stdc++.h>
using namespace std;

#define ll long long

string sgrid[10][9];
int ngrid[10][9];

bool isNum(string s) {
    for (auto c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void dfs(pair<int, int> v, vector<pair<int, int>> visited) {
    if (find(visited.begin(), visited.end(), v) != visited.end()) {
        ngrid[v.first][v.second] = -1;
    }
    visited.push_back(v);

    vector<string> tokens;
    stringstream check1(sgrid[v.first][v.second]);
    string intermediate;
    while (getline(check1, intermediate, '+')) {
        tokens.push_back(intermediate);
    }
    vector<pair<int, int>> neighbours;
    for (auto token : tokens) {
        int a = token[0] - 65;
        int b = token[1] - '0' - 1;
        neighbours.push_back({a, b});
    }

    int value = 0;
    for (auto u : neighbours) {
        int uval;
        if (ngrid[u.first][u.second] == -69) {
            dfs(u, visited);
        }
        uval = ngrid[u.first][u.second];
        if (uval == -1) {
            value = -1;
            break;
        } else {
            value += uval;
        }
    }
    ngrid[v.first][v.second] = value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sgrid[i][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (isNum(sgrid[i][j])) {
                ngrid[i][j] = stoi(sgrid[i][j]);
            } else {
                ngrid[i][j] = -69;
            }
        }
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (ngrid[i][j] == -69) {
                dfs({i, j}, {});
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (ngrid[i][j] == -1) {
                cout << "* ";
            } else {
                cout << ngrid[i][j] << " ";
            }
        }
        cout << "\n";
    }
}