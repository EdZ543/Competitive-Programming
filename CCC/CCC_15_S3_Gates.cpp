#include <bits/stdc++.h>
using namespace std;

#define ll long long

bitset<100005> docks;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g, p; cin >> g >> p;
    docks.flip();
    for (int i = 0; i < p; i++) {
        int dock; cin >> dock;
        bool good = false;
        int d = docks._Find_next(g-dock);
        if (d>g) {
            cout << i << "\n";
            return 0;
        }
        docks[d] = 0;
    }
    cout << p << "\n";
}