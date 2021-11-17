#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string hand; cin >> hand;
    vector<char> clubs, diamonds, hearts, spades;
    int clubPoints = 0, diamondPoints = 0, heartPoints = 0, spadePoints = 0;
    char curSuit = 'C';

    map<char, int> cardToPoints = {
        {'A', 4},
        {'K', 3},
        {'Q', 2},
        {'J', 1},
    };

    for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == 'C' || hand[i] == 'D' || hand[i] == 'H' || hand[i] == 'S') {
            curSuit = hand[i];
            continue;
        }
        int points = cardToPoints[hand[i]];
        if (curSuit == 'C') {
            clubs.push_back(hand[i]);
            clubPoints += points; 
        } else if (curSuit == 'D') {
            diamonds.push_back(hand[i]);
            diamondPoints += points;
        } else if (curSuit == 'H') {
            hearts.push_back(hand[i]);
            heartPoints += points;
        } else {
            spades.push_back(hand[i]);
            spadePoints += points;
        }
    }

    map<int, int> suitToPoints = {
        {0, 3},
        {1, 2},
        {2, 1}
    };
    
    clubPoints += suitToPoints[clubs.size()];
    diamondPoints += suitToPoints[diamonds.size()];
    heartPoints += suitToPoints[hearts.size()];
    spadePoints += suitToPoints[spades.size()];

    cout << "Cards Dealt Points\n";

    cout << "Clubs ";
    for (auto x : clubs) {
        cout << x << ' ';
    }
    cout << clubPoints << '\n';

    cout << "Diamonds ";
    for (auto x : diamonds) {
        cout << x << ' ';
    }
    cout << diamondPoints << '\n';

    cout << "Hearts ";
    for (auto x : hearts) {
        cout << x << ' ';
    }
    cout << heartPoints << '\n';

    cout << "Spades ";
    for (auto x : spades) {
        cout << x << ' ';
    }
    cout << spadePoints << '\n';

    cout << "Total " << clubPoints + diamondPoints + heartPoints + spadePoints;
}