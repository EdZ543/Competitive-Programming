#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int day = 1;
    set<pair<int, int>> custs;
    for (int i = 0; i < n; i++) {
        pair<int, int> a;
        cin >> a.first >> a.second;
        custs.insert(a);
    }
    priority_queue<pair<int, int>> rooms;
    
}