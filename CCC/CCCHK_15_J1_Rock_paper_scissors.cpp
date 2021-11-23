#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int aliceWins = 0;
    int bobWins = 0;
    string aliceShapes[N];
    for (int i = 0; i < N; i++) {
        cin >> aliceShapes[i];
    }
    string bobShapes[N];
    for (int i = 0; i < N; i++) {
        cin >> bobShapes[i];
    }
    for (int i = 0; i < N; i++) {
        if (aliceShapes[i] == "rock") {
            if (bobShapes[i] == "paper") {
                bobWins++;
            } else if (bobShapes[i] == "scissors") {
                aliceWins++;
            }
        } else if (aliceShapes[i] == "paper") {
            if (bobShapes[i] == "scissors") {
                bobWins++;
            } else if (bobShapes[i] == "rock") {
                aliceWins++;
            }
        } else if (aliceShapes[i] == "scissors") {
            if (bobShapes[i] == "rock") {
                bobWins++;
            } else if (bobShapes[i] == "paper") {
                aliceWins++;
            }
        }
    }
    cout << aliceWins << " " << bobWins;
}