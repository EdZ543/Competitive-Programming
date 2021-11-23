#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int ud = t, ol = 0, el = 0, round = 0;
        while (true) {
            if (ud == 1 && ol == 1) {
                cout << "Round " << round << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated\n";
                ud--;
                ol++;
                round++;
                cout << "Round " << round << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated\n";
                ol--;
                el++;
                round++;
                break;
            } else {
                cout << "Round " << round << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated\n";
                int udlosers = ud/2;
                int ollosers = ol/2;
                ud -= udlosers;
                ol -= ollosers;
                ol += udlosers;
                el += ollosers;
                round++;
            }
        }
        cout << "Round " << round << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated\n";
        cout << "There are " << round << " rounds.\n\n";
    }
}