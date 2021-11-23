#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        int away = 0;
        while (true) {
            int a = N - away;
            int b = N + away; 
            if (prime(a) && prime(b)) {
                cout << a << ' ' << b << '\n';
                break;
            }
            a % 2 == 0 ? away++ : away += 2;
        }
    }
}