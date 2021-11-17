#include <bits/stdc++.h>

using namespace std;

int main() {
    int wins = 0;
    for (int i = 0; i < 6; i++) {
        char result;
        cin >> result;
        if (result == 'W') {
            wins++;
        }
    }
    if (wins == 5 || wins == 6) {
        cout << "1";
    } else if (wins == 3 || wins == 4) {
        cout << "2";
    } else if (wins == 1 || wins == 2) {
        cout << "3";
    } else if (wins == 0) {
        cout << "-1";
    }
}