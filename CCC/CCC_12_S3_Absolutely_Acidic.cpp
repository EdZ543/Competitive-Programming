#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> freq(1001, 0);

    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        freq[r]++;
    }

    int maxf = 0;
    int smaxf = 0;
    vector<int> maxs;
    vector<int> smaxs;

    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == 0) continue;
        if (freq[i] > maxf) {
            smaxf = maxf;
            smaxs = maxs;
            maxf = freq[i];
            maxs = {i};
        } else if (freq[i] == maxf) {
            maxs.push_back(i);
        } else if (freq[i] > smaxf) {
            smaxf = freq[i];
            smaxs = {i};
        } else if (freq[i] == smaxf) {
            smaxs.push_back(i);
        }
    }

    if (maxs.size() > 1) {
        cout << abs(*max_element(maxs.begin(), maxs.end()) - *min_element(maxs.begin(), maxs.end())) << "\n";
    } else {
        int dif1 = abs(maxs[0] - *max_element(smaxs.begin(), smaxs.end()));
        int dif2 = abs(maxs[0] - *min_element(smaxs.begin(), smaxs.end()));
        cout << max(dif1, dif2) << "\n";
    }
}