#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b; cin >> a >> b;
    string res = "A";
    for (auto c : b) {
        if (c != '*') {
            auto it = find(begin(a), end(a), c);
            if (it != end(a)) {
                a.erase(it);
            } else {
                res = "N";
            }
        }
    }
    cout << res;
}