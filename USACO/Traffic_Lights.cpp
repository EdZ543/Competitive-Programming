#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, n; cin >> x >> n;
    set<int> lights;
    multiset<int> dists;
    lights.insert(0);
    lights.insert(x);
    dists.insert(x);

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        auto r = lights.upper_bound(p);
        auto l = r;
        l--;
        dists.erase(dists.find(*r-*l));
        dists.insert(p-*l);
        dists.insert(*r-p);
        lights.insert(p);
        auto ans = dists.end();
        ans--;
        cout << *ans << " ";
    }
}