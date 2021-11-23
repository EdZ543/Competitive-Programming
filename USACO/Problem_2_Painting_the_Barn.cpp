#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int grid[1001][1001];

int main(){
    setIO("paintbarn");
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        grid[a][b]++;
        grid[a][d]--;
        grid[c][b]--;
        grid[c][d]++;
    }
    int answer = 0;
    for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
            if (i) grid[i][j] += grid[i-1][j];
            if (j) grid[i][j] += grid[i][j-1];
            if (i && j) grid[i][j] -= grid[i-1][j-1];
            if (grid[i][j] == K) answer++;
        }
    }
    cout << answer;
}