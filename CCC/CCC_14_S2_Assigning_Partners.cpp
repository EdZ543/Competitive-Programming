#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string quality = "good";
    int N; cin >> N;
    vector<vector<string>> pairs(N, vector<string>(2));
    for (int i = 0; i < N; i++) cin >> pairs[i][0];
    for (int i = 0; i < N; i++) cin >> pairs[i][1];
    for (int i = 0; i < N; i++) {
        vector<string> current = pairs[i];
        sort(begin(current), end(current));
        for (int j = 0; j < N; j++) {
            vector<string> check = pairs[j];
            sort(begin(check), end(check));
            if (
                (check[0] == check[1]) ||
                (current[0] == check[0] &&
                current[1] != check[1]) ||
                (current[0] != check[0] &&
                current[1] == check[1])
            ) {
                quality = "bad";
                break;
            }
        }
    }
    cout << quality;
}