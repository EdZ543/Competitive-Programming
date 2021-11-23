#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int m, n;
    cin >> m >> n;
    int numSums = 0;

    for (int i = 1; i <= m; i++) {
        int otherDie = 10 - i;
        if (otherDie > 0 && otherDie <= n) {
            numSums++;
        }
    }

    if (numSums == 1) {
        cout << "There is 1 way to get the sum 10.";
    } else {
        cout << "There are " << numSums << " ways to get the sum 10.";
    }
} 