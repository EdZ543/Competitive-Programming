#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N; cin >> T >> N;
    vector<int> d(N);
    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    for (int i = 0; i < N; i++) cin >> p[i];
    sort(begin(d), end(d));
    sort(begin(p), end(p));
    int totalSpeed = 0;
    if (T == 1) {
       for (int i = 0; i < N; i++) {
           totalSpeed += max(d[i], p[i]);
       } 
    } else {
        for (int i = 0; i < N; i++) {
            totalSpeed += max(d[i], p[N-i-1]);
        }
    }
    cout << totalSpeed;
}