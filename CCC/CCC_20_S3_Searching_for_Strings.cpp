#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll P = 9973, M1 = 1e9+9, M2 = 1e9+7;
int fn[26], fh[26];
string n, h;

bool is_match() {
    for (int i = 0; i < 26; i++) {
        if (fn[i] != fh[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;
    if (n.size() > h.size()) {
        cout << 0 << "\n";
        return 0;
    }

    set<pair<ll, ll>> good;
    ll poly1 = 0, poly2 = 0, p_pow1 = 1, p_pow2 = 1;

    for (int i = 0; i < n.size(); i++) {
        fn[n[i]-'a']++;
        fh[h[i]-'a']++;

        poly1 = (poly1 * P + (h[i] - 'a')) % M1;
		poly2 = (poly2 * P + (h[i] - 'a')) % M2;

        p_pow1 = p_pow1 * P % M1;
		p_pow2 = p_pow2 * P % M2;
    }
    
    if (is_match()) good.insert({poly1, poly2});

    for (int i = n.size(); i < h.size(); i++) {
        fh[h[i]-'a']++;
        fh[h[i-n.size()]-'a']--;

		poly1 = (poly1 * P - p_pow1 * (h[i - n.size()] - 'a') % M1 + (h[i] - 'a') + M1) % M1;
		poly2 = (poly2 * P - p_pow2 * (h[i - n.size()] - 'a') % M2 + (h[i] - 'a') + M2) % M2;

        if (is_match()) good.insert({poly1, poly2});
    }

    cout << good.size() << "\n";
}