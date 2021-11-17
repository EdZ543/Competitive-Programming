#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int h, M;
    cin >> h >> M;

    int t = 1;
    while (true) {
        int A = -6 * pow(t, 4) + h * pow(t, 3) + 2 * pow(t, 2) + t;
        if (A <= 0) {
            cout << "The balloon first touches ground at hour:\n" << t;
            break;
        }
        if (t == M) {
            cout << "The balloon does not touch ground in the given time.";
            break;
        }
        t++;
    }
} 