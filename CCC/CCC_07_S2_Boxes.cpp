#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, vector<int>>> boxes(n);
    for (int i = 0; i < n; i++) {
        vector<int> dimensions(3);
        for (int j = 0; j < 3; j++) {
            cin >> dimensions[j];
        }
        sort(begin(dimensions), end(dimensions));
        int volume = dimensions[0] * dimensions[1] * dimensions[2];
        boxes[i].first = volume;
        boxes[i].second = dimensions;
    }
    sort(begin(boxes), end(boxes));
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        vector<int> dimensions(3);
        for (int j = 0; j < 3; j++) {
            cin >> dimensions[j];
        }
        sort(begin(dimensions), end(dimensions));
        bool fits = false;
        for (auto box : boxes) {
            if (dimensions[0] <= box.second[0] && dimensions[1] <= box.second[1] && dimensions[2] <= box.second[2]) {
                fits = true;
                cout << box.first << '\n';
                break;
            }
        }
        if (!fits) cout << "Item does not fit.\n";
    }
}