#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int bruh; cin >> bruh;
        pair<int, int> p(bruh, i);
        a[i] = p;
    }
    sort(a.begin(), a.end());

    bool good = false;
    for (int w = 0; w < n; w++) {
        int r = n - 1;
        for (int l = 0; l < n; l++) {
            while (a[w].first + a[l].first + a[r].first > x && r > l) {
                r--;
            }
            if (a[w].first + a[l].first + a[r].first == x && w != l && l != r && r != w) {
                good = true;
                cout << a[w].second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1; 
                break;
            }
        }
        if (good) break;
    }
    if (!good) cout << "IMPOSSIBLE";
}