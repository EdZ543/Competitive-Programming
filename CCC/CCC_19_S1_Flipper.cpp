#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tl = 1, tr = 2, bl = 3, br = 4;
    string flips; cin >> flips;
    for (auto c : flips) {
        if (c == 'H') {
            int l = tl;
            tl = bl;
            bl = l;

            int r = tr;
            tr = br;
            br = r;
        } else {
            int t = tl;
            tl = tr;
            tr = t;

            int b = bl;
            bl = br;
            br = b;
        }
    }
    cout << tl << ' ' << tr << '\n' << bl << ' ' << br;
}