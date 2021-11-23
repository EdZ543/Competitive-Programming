#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int n, m;
    cin >> n >> m;
    vector<string> adjectives;

    for (int i = 0; i < n; i++) {
        string adjective;
        cin >> adjective;
        adjectives.push_back(adjective);
    }

    for (int i = 0; i < m; i++) {
        string noun;
        cin >> noun;
        for (string adjective : adjectives) {
            cout << adjective << " as " << noun << "\n";
        }
    }
} 