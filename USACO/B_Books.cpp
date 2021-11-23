#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, x = 0, res = 0;
    for (int r = 0; r < n; r++) {
        x += a[r];
        while (x > t) {
            x -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res;
}