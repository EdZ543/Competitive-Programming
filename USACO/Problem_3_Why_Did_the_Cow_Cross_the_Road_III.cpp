#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, k, r;
vector<pair<int, int>> roads[101][101];
vector<vector<bool>> visited(101, vector<bool>(101, false));
bool grid[101][101];
vector<int> comps;
int curr_size = 0;
int sol = 0;

void floodfill(int r, int c) {
	if (
		(r < 1 || r > n || c < 1 || c > n)  // if out of bounds
		|| visited[r][c]  // already visited this square
	) return;

	visited[r][c] = true; // mark current square as visited
	if (grid[r][c]) curr_size++; // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
    vector<pair<int, int>> directions = {{r-1, c}, {r, c+1}, {r+1, c}, {r, c-1}};
    for (auto road : roads[r][c]) {
        directions.erase(remove(directions.begin(), directions.end(), road), directions.end());
    }
    // cout << r << " " << c << "\n";
    // for (auto d : directions) {
    //     cout << d.first << " " << d.second << "\n";
    // }
    // cout << "\n";
    for (auto d : directions) {
        floodfill(d.first, d.second);
    }
}

int main(){
    setIO("countcross");
    cin >> n >> k >> r; 
    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        roads[r1][c1].push_back({r2, c2});
        roads[r2][c2].push_back({r1, c1});
    }
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        grid[r][c] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] && !visited[i][j]) {
                curr_size = 0;
                floodfill(i, j);
                comps.push_back(curr_size);
            }
        }
    }

    for (int i = 0; i < comps.size(); i++) {
        for (int j = i + 1; j < comps.size(); j++) {
            sol += comps[i] * comps[j];
        }
    }

    cout << sol << "\n";
}