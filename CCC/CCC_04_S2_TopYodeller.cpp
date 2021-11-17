#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> scores(n, 0);
    vector<int> worstRanks(n, INT_MIN);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int score; cin >> score;
            scores[j] += score;
        }
        set<int, greater<int>> sorted;
        for (auto score : scores) {
            sorted.insert(score);
        }
        for (int j = 0; j < n; j++) {
            auto scoreit = sorted.find(scores[j]);
            int rank = distance(begin(sorted), scoreit) + 1;
            worstRanks[j] = max(worstRanks[j], rank);
        }
    }
    int topScore = INT_MIN;
    vector<int> topYodellers;
    for (int i = 0; i < n; i++) {
        if (scores[i] > topScore) {
            topYodellers.clear();
            topYodellers.push_back(i + 1);
            topScore = scores[i];
        } else if (scores[i] == topScore) {
            topYodellers.push_back(i + 1);
        }
    }
    for (auto topYodeller : topYodellers) {
        cout << "Yodeller " << topYodeller << " is the TopYodeller: score " << topScore << ", worst rank " << worstRanks[topYodeller-1] <<  '\n';
    }
}