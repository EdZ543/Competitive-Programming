#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    string word;
    cin >> word;
    string valid = "YES";

    for (char c : word) {
        if (c != 'I' && c != 'O' && c != 'S' && c != 'H' && c != 'Z' && c != 'X' && c != 'N') {
            valid = "NO";
        }
    }

    cout << valid;
} 