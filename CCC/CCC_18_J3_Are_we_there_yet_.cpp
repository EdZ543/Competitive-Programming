#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<int> positions = {0};
    int position = 0;

    for (int i = 0; i < 4; i++) {
        int distance;
        cin >> distance;
        position += distance;
        positions.push_back(position);
    }

    for (int i = 0; i < positions.size(); i++) {
        string line;
        for (int j = 0; j < positions.size(); j++) {
            int distance = abs(positions[i] - positions[j]);
            line += to_string(distance) + ' ';
        }
        cout << line << '\n';
    }
} 