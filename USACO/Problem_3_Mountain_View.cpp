#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool blocks(pair<int, int> peakA, pair<int, int> peakB) {
    return abs(peakA.first - peakB.first) <= peakA.second - peakB.second;
}

int main(){
    setIO("mountains");
    int N; cin >> N;
    vector<pair<int, int>> peaks;

    for (int i = 0; i < N; i++) {
        pair<int, int> peak; cin >> peak.first >> peak.second;
        bool distinct = true;
        for (int i = 0; i < peaks.size(); i++) {
            if (blocks(peaks[i], peak)) {
                distinct = false;
                break;
            }
            if (blocks(peak, peaks[i])) {
                peaks.erase(begin(peaks) + i);
                i--;
            }
        }
        if (distinct) peaks.push_back(peak);
    }

    cout << peaks.size();
}