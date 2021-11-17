#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("hayfeast");
    ll n, m; cin >> n >> m;
    vector<ll> f(n), s(n);
    for (ll i = 0; i < n; i++) cin >> f[i] >> s[i];

    multiset<ll> spices;
    ll l = 0, flavour = 0, sol = LLONG_MAX;
    for (ll r = 0; r < n; r++) {
        flavour += f[r];
        spices.insert(s[r]);
        while (flavour - f[l] >= m) {
            flavour -= f[l];
            spices.erase(spices.find(s[l]));
            l++;
        }
        if (flavour >= m) sol = min(sol, *spices.rbegin());
    }
    cout << sol << "\n";
}