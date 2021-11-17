#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cardgame");
    
    int N; cin >> N;
    set<int> bessie;
    set<int> bessieLow;
    set<int> bessieHigh;
    for (int i = 1; i <= N*2; i++) bessie.insert(i);
    vector<int> elsie;
    for (int i = 0; i < N; i++) {
        int card; cin >> card;
        bessie.erase(card);
        elsie.push_back(card);
    }
    int index = 0;
    for (auto card : bessie) {
        if (index < N/2) {
            bessieLow.insert(card);
        } else {
            bessieHigh.insert(card);
        }
        index++;
    }
    int score = 0;
    for (int i = 0; i < N; i++) {
        if (i < N/2) {
            auto it = bessieHigh.upper_bound(elsie[i]);
            if (it == bessieHigh.end()) {
                bessieHigh.erase(bessieHigh.begin());
            } else {
                bessieHigh.erase(it);
                score++;
            }
        } else {
            auto it = bessieLow.upper_bound(elsie[i]);
            if (it != bessieLow.begin()) it--;
            if (*it < elsie[i]) {
                score++;
                bessieLow.erase(it);
            } else {
                bessieLow.erase(--bessieLow.end());
            }
        }
    }
    cout << score;
}