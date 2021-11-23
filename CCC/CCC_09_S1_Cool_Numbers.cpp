#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b; cin >> a >> b;
    long long cool = 0;
    long long start = 1;
    while (start * start * start < a) {
        start++;
    }
    for (long long t = start; t*t*t <= b; t++) {
        long long i = t*t*t;
        long long sr = sqrt(i);
        long long cr = cbrt(i);
        bool s = sr * sr == i || (sr - 1) * (sr - 1) == i || (sr + 1) * (sr + 1) == i;
        if (!s) {
            continue;
        }
        bool c = cr * cr * cr == i ||
        (cr - 1) * (cr - 1) * (cr - 1) == i ||
        (cr + 1) * (cr + 1) * (cr + 1) == i;
        if (c) {
            cool++;
        }
    }
    cout << cool;
}