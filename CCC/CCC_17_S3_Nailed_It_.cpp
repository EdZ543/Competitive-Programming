#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll ans1, ans2, buckets[2004], sums[4004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        buckets[a]++;
    }

    for (int i = 1; i <= 2000; i++) {
        if (buckets[i]) {
            for (int j = i; j <= 2000; j++) {
                if (i == j) {
                    sums[i+j] += buckets[i] / 2;
                } else if (buckets[j]) {
                    sums[i+j] += min(buckets[i], buckets[j]);
                }
            }
        }
    }

    for (int i = 1; i <= 4000; i++) {
        if (sums[i] > ans1) {
            ans1 = sums[i];
            ans2 = 1;
        } else if (sums[i] == ans1) {
            ans2++;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}