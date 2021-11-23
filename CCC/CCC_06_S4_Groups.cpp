#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        int grid[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }

        bool hasAssociativity = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (grid[i][grid[j][k]] != grid[grid[i][j]][k]) hasAssociativity = false;
                }
            }
        }
        if (!hasAssociativity) {
            cout << "no\n";
            continue;
        }

        int verIdentity = INT_MAX;
        for (int i = 1; i <= n; i++) {
            bool good = true;
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] != j) {
                    good = false;
                }
            }
            if (good) {
                verIdentity = i;
            }
        }
        int horIdentity = INT_MAX;
        for (int j = 1; j <= n; j++) {
            bool good = true;
            for (int i = 1; i <= n; i++) {
                if (grid[i][j] != i) {
                    good = false;
                }
            }
            if (good) {
                horIdentity = j;
            }
        }
        if (verIdentity == INT_MAX || verIdentity != horIdentity) {
            cout << "no\n";
            continue;
        }

        bool hasInverse = true;
        for (int i = 1; i <= n; i++) {
            bool good = false;
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == verIdentity) good = true;
            }
            if (!good) hasInverse = false;
        }
        for (int j = 1; j <= n; j++) {
            bool good = false;
            for (int i = 1; i <= n; i++) {
                if (grid[i][j] == verIdentity) good = true;
            }
            if (!good) hasInverse = false;
        }
        if (!hasInverse) {
            cout << "no\n";
            continue;
        }

        cout << "yes\n";
    }
}