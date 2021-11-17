#include <bits/stdc++.h>
using namespace std;

#define ll long long

int getChances(vector<pair<int, int>> games, vector<int> S, int T, int game, char winar, int chance) {
    int PA, PB;
    if (winar == 'A') {
        PA = 3;
        PB = 0;
    } else if (winar == 'B') {
        PA = 0;
        PB = 3;
    } else {
        PA = 1;
        PB = 1;
    }
    S[games[game].first] += PA;
    S[games[game].second] += PB;

    if (game == games.size() - 1) {
        int favPoints = S[T];
        sort(S.begin(), S.end());
        if (S[4] == favPoints && S[3] != favPoints) {
            chance++;
        }
    } else {
        chance = getChances(games, S, T, game + 1, 'A', chance);
        chance = getChances(games, S, T, game + 1, 'B', chance);
        chance = getChances(games, S, T, game + 1, 'T', chance);
    }

    return chance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, G; cin >> T >> G;
    vector<int> S(5, 0);
    vector<pair<int, int>> games = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4}
    };

    for (int i = 0; i < G; i++) {
        int A, B, SA, SB; cin >> A >> B >> SA >> SB;
        int PA, PB;
        if (SA > SB) {
            PA = 3;
            PB = 0;
        } else if (SA < SB) {
            PA = 0;
            PB = 3;
        } else {
            PA = 1;
            PB = 1;
        }
        S[A] += PA;
        S[B] += PB;
        games.erase(remove(games.begin(), games.end(), make_pair(min(A, B), max(A, B))), games.end());
    }

    int chance = 0;
    chance = getChances(games, S, T, 0, 'A', chance);
    chance = getChances(games, S, T, 0, 'B', chance);
    chance = getChances(games, S, T, 0, 'T', chance);

    cout << chance;
}