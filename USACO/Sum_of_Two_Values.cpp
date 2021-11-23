#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    vector<ll> archive = a;
    sort(a.begin(), a.end());

    int r = n - 1;
    bool good = false;
    for (int l = 0; l < n; l++) {
        while (a[l] + a[r] > x && r - 1 > l) {
            r--;
        }
        if (a[l] + a[r] == x && l != r) {
            auto itl = find(archive.begin(), archive.end(), a[l]);
            int posl = distance(archive.begin(), itl);
            vector<ll> archive2 = archive;
            archive2[posl] = -1;
            auto itr = find(archive2.begin(), archive2.end(), a[r]);
            int posr = distance(archive2.begin(), itr);
            cout << posl + 1 << " " << posr + 1;
            good = true;
            break;
        }
    }
    if (!good) cout << "IMPOSSIBLE";
}