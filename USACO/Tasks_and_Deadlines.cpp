#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());
    int time = 0;
    int reward = 0;
    for (auto task : tasks) {
        time += task.first;
        reward += task.second - time;
    }
    cout << reward;
}