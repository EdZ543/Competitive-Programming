#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int grid[100][100] = {0};
        bool allones[100] = {true};
		fill_n(allones, 100, true);
        int x, y; cin >> x >> y;
        int r = 50, c = 50;
        int n = x;
        int sideLength = 1;
        int numOfSideLength = 2;
        int sideTraversed = 0;
        char direction = 'D';
        int lastrow = 0;

        grid[r][c] = n;
        if (n >= 10) {
            allones[c] = false;
        }
        n++;
        r++;

        while (n <= y) {
            lastrow = max(lastrow, r);
            grid[r][c] = n;
            if (n >= 10) {
                allones[c] = false;
            }
            n++;
            sideTraversed++;

            if (sideTraversed == sideLength) {
                if (direction == 'D') direction = 'R';
                else if (direction == 'R') direction = 'U';
                else if (direction == 'U') direction = 'L';
                else if (direction == 'L') direction = 'D';
                sideTraversed = 0;
                numOfSideLength--;
            }

            if (numOfSideLength == 0) {
                sideLength++;
                numOfSideLength = 2;
            }

            if (direction == 'D') r++;
            else if (direction == 'R') c++;
            else if (direction == 'U') r--;
            else if (direction == 'L') c--;
        }

        if (sideTraversed < sideLength) {
            for (int i = sideTraversed; i < sideLength - 1; i++) {
                grid[r][c] = -1;
                if (direction == 'D') r++;
				else if (direction == 'R') c++;
				else if (direction == 'U') r--;
				else if (direction == 'L') c--;
            }
        }

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (grid[i][j] == -1) {
					if (allones[j]) {
						cout << " ";
					} else {
                    	cout << "  ";
					}
					if (grid[i][j+1] != 0) {
						cout << ' ';
					}
					if (grid[i][j+1] == 0 && i != lastrow) {
						cout << '\n';
					}
                } else if (grid[i][j] != 0) {
                    if (!allones[j] && grid[i][j] < 10) {
                        cout << ' ';
                    }
                    cout << grid[i][j];
					if (grid[i][j+1] != 0) {
						cout << ' ';
					}
					if (grid[i][j+1] == 0 && i != lastrow && x != y) {
						cout << '\n';
					}
                }
            }
        }
        cout << '\n';
        if (t < T - 1) {
            cout << "\n";
        }
    }
}