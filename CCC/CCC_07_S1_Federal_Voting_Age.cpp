#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int y, m, d; cin >> y >> m >> d;
        if (y > 1989) {
            cout << "No\n";
        } else if (y < 1989) {
            cout << "Yes\n";
        } else {
            if (m > 2) {
                cout << "No\n";
            } else if (m < 2) {
                cout << "Yes\n";
            } else {
                if (d > 27) {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            }
        }
    }
}