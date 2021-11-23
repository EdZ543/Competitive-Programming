#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) cin >> events[i].second >> events[i].first;
    sort(events.begin(), events.end());

    multiset<int> ends;
    int movies = 0;
    for (int i = 0; i < k; i++) ends.insert(0);

    for (int i = 0; i < n; i++) {
        auto it = ends.upper_bound(events[i].second);
        if (it == ends.begin()) continue;
        ends.erase(--it);
        ends.insert(events[i].first);
        movies++;
    }

    cout << movies;
}