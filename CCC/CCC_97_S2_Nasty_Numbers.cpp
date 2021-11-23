#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    for (int k = 0; k < N; k++) {
        int n; cin >> n;
        vector<int> differences;
        vector<int> sums;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                int j = n / i;
                differences.push_back(abs(j - i));
                sums.push_back(i + j);
            }
        }
        string nasty = " is not nasty\n";
        for (auto difference : differences) {
            if (find(sums.begin(), sums.end(), difference) != sums.end()) {
                nasty = " is nasty\n";
                break;
            }
        }
        cout << n << nasty;
    }
}