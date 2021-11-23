#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_N = 1000;

string grid[MAX_N];
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
int curr_size = 0;  // reset to 0 each time we start a new component
int curr_p = 0;

void floodfill(int r, int c, int color){
	if (
		(r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
		|| grid[r][c] != color  // wrong color
		|| visited[r][c]  // already visited this square
	) return;

	visited[r][c] = true; // mark current square as visited
	curr_size++; // increment the size for each square we visit
    if (c+1 >= col_num || grid[r][c+1] == '.') curr_p++;
    if (c-1 < 0 || grid[r][c-1] == '.') curr_p++;
    if (r-1 < 0 || grid[r-1][c] == '.') curr_p++;
    if (r+1 >= row_num || grid[r+1][c] == '.') curr_p++;

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
    setIO("perimeter");
    cin >> row_num;
    col_num = row_num;
    for (int i = 0; i < row_num; i++) cin >> grid[i];
    int max_a = 0, min_p = INT_MAX;

	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (!visited[i][j] && grid[i][j] != '.') {
				curr_size = 0;
                curr_p = 0;
				/*
				 * start a flood fill if the square hasn't already been visited,
				 * and then store or otherwise use the component size
				 * for whatever it's needed for
				 */
				floodfill(i, j, grid[i][j]);
                if (curr_size > max_a) {
                    max_a = curr_size;
                    min_p = curr_p;
                } else if (curr_size == max_a) {
                    min_p = min(min_p, curr_p);
                }
			}
		}
	}
    cout << max_a << " " << min_p << "\n";
	return 0;
}