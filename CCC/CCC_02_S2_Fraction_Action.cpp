#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d; cin >> n >> d;
    int x = 0;
    if (n % d == 0) {
        int res = n / d;
        cout << res;
    } else {
        while (n >= d) {
            n -= d;
            x++;
        }
        int factor = 2;
        while (true) {
            if (n % factor == 0 && d % factor == 0) {
                n /= factor;
                d /= factor;
                factor = 2;
            } else {
                factor++;
                if (factor > min(n, d)) {
                    break;
                }
            }
        }
        if (x != 0) {
            cout << x << ' ';
        }
        cout << n << '/' << d;
    }
    cout << '\n';
}