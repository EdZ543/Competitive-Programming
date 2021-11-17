#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool storeCmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(){
    setIO("rental");
    int N, M, R; cin >> N >> M >> R;
    vector<int> cows(N);
    vector<pair<int, int>> stores(M);
    vector<int> farmers(R);

    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> stores[i].first >> stores[i].second;
    }

    for (int i = 0; i < R; i++) {
        cin >> farmers[i];
    }

    sort(begin(cows), end(cows), greater<int>());
    sort(begin(stores), end(stores), storeCmp);
    sort(begin(farmers), end(farmers), greater<int>());
    
    long long profit = 0;
    int store = 0;
    int farmer = 0;
    int i = 0;
    while (i < N) {
        int saleP = 0;
        int milk = cows[i];
        int tempStore = store;
        int last = 0;
        while (tempStore < M) {
            int rest = min(milk, stores[tempStore].first);
            saleP += rest * stores[tempStore].second;
            milk -= rest;
            
            if (milk == 0) {
                last = rest;
                break;
            } else {
                tempStore++;
            }
        }

        if (saleP > farmers[farmer] || farmer >= R) {
            profit += saleP;
            store = tempStore;
            if (store < M) stores[store].first -= last;
            i++;
        } else {
            profit += farmers[farmer];
            farmer++;
            N--;
        }
    }

   cout << profit;
}