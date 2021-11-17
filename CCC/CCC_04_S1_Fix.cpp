#include <bits/stdc++.h>
using namespace std;

bool in(string s, vector<string> v) {
    return find(begin(v), end(v), s) != end(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b, c; cin >> a >> b >> c;
        vector<string> ap, bp, cp, as, bs, cs; 
        for (int j = 0; j <= a.size(); j++) {
            ap.push_back(a.substr(0, j));
            as.push_back(a.substr(a.size() - j, j));
        }
        for (int j = 0; j <= b.size(); j++) {
            bp.push_back(b.substr(0, j));
            bs.push_back(b.substr(b.size() - j, j));
        }
        for (int j = 0; j <= c.size(); j++) {
            cp.push_back(c.substr(0, j));
            cs.push_back(c.substr(c.size() - j, j));
        }
        if (
            in(a, bp) ||
            in(a, cp) ||
            in(a, bs) ||
            in(a, cs) ||
            in(b, ap) ||
            in(b, cp) ||
            in(b, as) ||
            in(b, cs) ||
            in(c, ap) ||
            in(c, bp) ||
            in(c, as) ||
            in(c, bs)
        ) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}