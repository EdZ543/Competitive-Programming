#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    double smallest = DBL_MAX;
    vector<double> villages(N);
    for (int i = 0; i < N; i++) cin >> villages[i];
    sort(begin(villages), end(villages));
    for (int i = 0; i < N; i++) {
        if (i == 0 || i == N - 1) {
            continue;
        }
        double prev = villages[i-1];
        double next = villages[i+1];
        double curr = villages[i];
        double leftmost = abs(curr - prev) / 2;
        double rightmost = abs(next - curr) / 2;
        double size = leftmost + rightmost;
        smallest = min(smallest, size);  
    }
    cout << fixed;
    cout << setprecision(1);
    cout << smallest;
}