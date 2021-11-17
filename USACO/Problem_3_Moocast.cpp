#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool is_connected[200][200];
vector<bool> visited;
int n;

int dfs(int node) {
    int cows = 1;
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && is_connected[node][i]) {
            cows += dfs(i);
        }
    }
    return cows;
}

int main(){
    setIO("moocast");
    cin >> n;
    vector<int> x(n), y(n), p(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dist = pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2);
            int rad = pow(p[i], 2);
            if (dist <= rad) is_connected[i][j] = true;
        }
    }

    int sol = 0;
    for (int i = 0; i < n; i++) {
        visited.assign(n, false);
        sol = max(sol, dfs(i));
    }

    cout << sol;
}