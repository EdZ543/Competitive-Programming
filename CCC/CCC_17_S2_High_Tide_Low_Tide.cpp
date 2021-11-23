#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> m(N);
    for (int i = 0; i < N; i++) cin >> m[i];
    sort(begin(m), end(m));
    int middle = N / 2;
    if (N % 2 == 0) {
        middle--;
    }
    vector<int> lows;
    for (int i = middle; i >= 0; i--) {
        lows.push_back(m[i]);
    }
    vector<int> highs;
    for (int i = middle + 1; i < N; i++) {
        highs.push_back(m[i]);
    }
    for (int i = 0; i < highs.size(); i++) {
        cout << lows[i] << ' ' << highs[i] << ' ';
    }
    if (N % 2 != 0) {
        cout << lows.back();
    }
}