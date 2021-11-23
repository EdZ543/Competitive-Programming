#include <bits/stdc++.h>
using namespace std;

int fact(int x) {
    if (x == 0 || x == 1) {
        return 1;
    }
    return x * fact(x-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int J; cin >> J;
    if (J < 4) {
        cout << 0;
    } else {
        int n = J-1;
        int c = (n*n*n-3*n*n+2*n)/6;
        cout << c;
    }
}