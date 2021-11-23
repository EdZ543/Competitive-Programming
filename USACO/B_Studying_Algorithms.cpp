#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X; cin >> N >> X;
    vector<int> w(N);
    for (int i = 0; i < N; i++) cin >> w[i];
    sort(w.begin(), w.end());

    int sum = 0;
    bool good = false;
    for (int i = 0; i < N; i++) {
        sum += w[i];
        if (sum > X) {
            cout << i;
            good = true;
            break;
        }
    }
    if (!good) cout << N;
}