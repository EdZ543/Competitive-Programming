#include <bits/stdc++.h>

using namespace std;

int main() {
    int C;
    cin >> C;
    int Clines[C * 2];
    int CbestFish = 0;
    for (int i = 0; i < C * 2; i++) {
        cin >> Clines[i];
    }
    for (int i = 0; i < C * 2; i+=2) {
        int fish = Clines[i] * Clines[i + 1];
        if (fish > CbestFish) {
            CbestFish = fish;
        }
    }
    
    int N;
    cin >> N;
    int Nlines[N * 2];
    int NbestFish = 0;
    for (int i = 0; i < N * 2; i++) {
        cin >> Nlines[i];
    }
    for (int i = 0; i < N * 2; i+=2) {
        int fish = Nlines[i] * Nlines[i + 1];
        if (fish > NbestFish) {
            NbestFish = fish;
        }
    }

    if (CbestFish > NbestFish) {
        cout << "Casper";
    } else if (NbestFish > CbestFish) {
        cout << "Natalie";
    } else {
        cout << "Tie";
    }
}