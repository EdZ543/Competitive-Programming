#include <bits/stdc++.h>
using namespace std;

bool cmp (const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second > b.second) {
        return false;
    } else {
        return string(a.first) > b.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<string, int>> computers;
    string secondName = "";
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        int R, S, D; cin >> R >> S >> D;
        int value = 2*R+3*S+D;
        computers.push_back({name, value});
    }
    sort(begin(computers), end(computers), cmp);
    if (computers.size() > 0) {
        cout << computers.back().first << '\n';
    }
    if (computers.size() > 1) {
        cout << computers[computers.size()-2].first;
    }
}