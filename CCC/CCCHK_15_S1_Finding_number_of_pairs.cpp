#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, M; cin >> n >> M;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(begin(a), end(a));
    ll res = 0;
    ll r = n - 1;
    for (ll l = 0; l < r; l++) {
        while (a[l] + a[r] > M) {
            r--;
        }
        if (l < r) {
            res += r - l;
        }
    }
    ll max = pow(10, 9) + 7;
    cout << (res < max ? res : res % max);
}