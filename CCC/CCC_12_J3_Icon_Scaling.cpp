#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int k;
    cin >> k;
    vector<vector<char>> iconLines = {
        {'*', 'x', '*'},
        {' ', 'x', 'x'},
        {'*', ' ', '*'}
    };
    for (int i = 0; i < iconLines.size(); ++i) {
        string line;
        for (int j = 0; j < iconLines[i].size(); ++j) {
            for (int x = 0; x < k; ++x) {
                line += iconLines[i][j];
            }
        }
        for (int y = 0; y < k; ++y) {
                cout << line << "\n";
        }
    }
} 