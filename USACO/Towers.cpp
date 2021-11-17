#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    multiset<int> towers;
    towers.insert(INT_MAX);
    for (int i = 0; i < n; i++) {
        int cube; cin >> cube;
        auto it = towers.upper_bound(cube);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(cube);
    }
    cout << towers.size();
}