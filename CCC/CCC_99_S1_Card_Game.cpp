#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int A = 0, B = 0;

void score(char currentPlayer, int score) {
    if (currentPlayer == 'A') {
        A += score;
    } else {
        B += score;
    }
    cout << "Player " << currentPlayer << " scores " << score << " point(s).\n";
}

bool nothigh(string card) {
    return card != "jack"
    && card != "queen"
    && card != "king"
    && card != "ace"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char currentPlayer = 'A';
    vector<string> cards(52);
    for (int i = 0; i < 52; i++) cin >> cards[i];
    for (int i = 0; i < 52; i++) {
        if (cards[i] == "ace") {
            if (i < 48 && nothigh(cards[i+1]) && nothigh(cards[i+2]) && nothigh(cards[i+3]) && nothigh(cards[i+4])) {
                score(currentPlayer, 4);
            }
        } else if (cards[i] == "king") {
            if (i < 49 && nothigh(cards[i+1]) && nothigh(cards[i+2]) && nothigh(cards[i+3])) {
                score(currentPlayer, 3);
            }
        } else if (cards[i] == "queen") {
            if (i < 50 && nothigh(cards[i+1]) && nothigh(cards[i+2])) {
                score(currentPlayer, 2);
            }
        } else if (cards[i] == "jack") {
            if (i < 51 && nothigh(cards[i+1])) {
                score(currentPlayer, 1);
            }
        }
        currentPlayer = currentPlayer == 'A' ? 'B' : 'A';
    }
    cout << "Player A: " << A << " point(s).\n";
    cout << "Player B: " << B << " point(s).";
}