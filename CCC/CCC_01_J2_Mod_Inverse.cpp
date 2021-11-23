#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int x, m;
    cin >> x >> m;

    string n = "No such integer exists.";
    for (int i = 1; i < m; i++) {
        if ((x * i) % m == 1) {
            n = to_string(i);
            break;
        }
    }
    cout << n;
} 