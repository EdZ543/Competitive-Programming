#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, m; cin >> K >> m;
    vector<int> friends(K);
    for (int i = 0; i < K; i++) friends[i] = i+1;
    for (int i = 0; i < m; i++) {
        int r; cin >> r;
        vector<int> removed;
        for (int j = 0; j < friends.size(); j++) {
            if ((j + 1) % r != 0) {
                removed.push_back(friends[j]);
            }
        }
        friends = removed;
    }
    for (auto buddy: friends) {
        cout << buddy << '\n';
    }
}