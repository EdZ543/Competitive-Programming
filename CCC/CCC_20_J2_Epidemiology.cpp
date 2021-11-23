#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int P, N, R;
    cin >> P >> N >> R;

    int day = 0;
    int infected = N;
    int canInfect = N;

    while (infected <= P) {
        day++;
        canInfect *= R;
        infected += canInfect;
    }

    cout << day;
} 