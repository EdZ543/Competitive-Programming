#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<double> streams(n);
    for (int i = 0; i < n; i++) cin >> streams[i];
    while (true) {
        double a; cin >> a;
        if (a == 77) {
            break;
        }
        if (a == 99) {
            double streamSplit, percentLeft; cin >> streamSplit >> percentLeft;
            streamSplit--;
            double left = streams[streamSplit] * (percentLeft / 100);
            double right = streams[streamSplit] - left;
            streams[streamSplit] = left;
            streams.insert(begin(streams) + streamSplit + 1, right);
        }
        if (a == 88) {
            double toJoin; cin >> toJoin;
            toJoin--;
            streams[toJoin] += streams[toJoin + 1];
            streams.erase(begin(streams) + toJoin + 1);
        }
    }
    for (auto stream : streams) {
        cout << round(stream) << ' ';
    }
}