#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n; 
vector<ll> p, w, d;

ll getTime(ll x) {
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        if (p[i] + d[i] < x) {
            total += w[i] * (x - p[i] - d[i]);
        } else if (p[i] - d[i] > x) {
            total += w[i] * (p[i] - d[i] - x);
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    p.assign(n, 0);
    w.assign(n, 0);
    d.assign(n, 0);
    for (ll i = 0; i < n; i++) cin >> p[i] >> w[i] >> d[i];

    ll l = *min_element(p.begin(), p.end());
    ll r = *max_element(p.begin(), p.end());
    while (l <= r) {
        ll m = (l+r)/2;
        ll time = getTime(m);
        ll ltime = getTime(m-1);
        ll rtime = getTime(m+1);
        if ((ltime == time && time == rtime) || (ltime > time && time < rtime)) {
            cout << time << "\n";
            break;
        }
        if (time < rtime) {
            r = m - 1;
        } else if (time < ltime) {
            l = m + 1;
        }
    }
}