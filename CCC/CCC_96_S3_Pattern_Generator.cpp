#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<string> out;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            if (i <= n - k) {
                arr.push_back(0);
            } else {
                arr.push_back(1);
            }
        }
        cout << "The bit patterns are\n";
        do {
            string tmp = "";
            for (auto x : arr) {
                tmp += to_string(x);
            }
            out.push(tmp);
        } while (next_permutation(arr.begin(), arr.end()));
        while (!out.empty()) {
            cout << out.top() << "\n";
            out.pop();
        }
        cout << "\n";
    }
}