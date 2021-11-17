#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n; cin >> n;
    long long prefixSums[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        long long x; cin >> x;
        sum += x;
        prefixSums[i] = sum;
    }
    long long best = INT_MIN;
    long long curSmalSub = 0;
    for (long long i = 0; i < n; i++) {
        best = max(best, prefixSums[i]-curSmalSub); 
        curSmalSub = min(curSmalSub, prefixSums[i]);
    }
    cout << best;
}