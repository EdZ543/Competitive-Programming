#include <bits/stdc++.h>
using namespace std;

#define ll long long

int memo[251][251][251] = {0};

int pi(int n, int k, int min) {
    if (memo[n][k][min] != 0) {
        return memo[n][k][min];
    }
    int result = 0;
    if (k == n || k == 1) {
        result = 1;
    } else {
        for (int i = min; i <= n / k; i++) {
            result += pi(n - i, k - 1, i);
        }
    }
    memo[n][k][min] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    cout << pi(n, k, 1);
}