#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        deque<int> top;
        deque<int> branch;
        for (int i = 0; i < n; i++) {
            int car; cin >> car;
            top.push_front(car);
        }
        int needed = 1;
        bool yum = true;
        while (top.size() != 0 || branch.size() != 0) {
            if (top.size() != 0 && top.front() == needed) {
                top.pop_front();
                needed++;
            } else if (branch.size() != 0 && branch.front() == needed) {
                branch.pop_front();
                needed++;
            } else if (top.size() != 0) {
                branch.push_front(top.front());
                top.pop_front();
            } else {
                yum = false;
                break;
            }
        }
        yum ? cout << "Y\n" : cout << "N\n";
    }
}