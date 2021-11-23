#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int X, Y;
    cin >> X >> Y;

    for (int i = X; i <= Y; i++) {
        if ((i - X) % 4 == 0 && (i - X) % 2 == 0 && (i - X) % 3 == 0 && (i - X) % 5 == 0) {
            cout << "All positions change in year " << i << "\n";
        }
    }
} 