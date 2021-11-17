#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
    sort(begin(a), end(a));
    double fastest = 0;
    for (int i = 0; i < N - 1; i++) {
        double time = a[i+1].first - a[i].first;
        double distance = abs(a[i+1].second - a[i].second);
        double speed = distance / time;
        fastest = max(fastest, speed);
    }
    cout << setprecision(100) << fastest;
}