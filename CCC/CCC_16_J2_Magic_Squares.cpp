#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<vector<int>> square;
    bool magic = true;

    for (int i = 0; i < 4; i++) {
        vector<int> row;
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            row.push_back(num);
        }
        square.push_back(row);
    }

    int magicSum = square[0][0] + square[0][1] + square[0][2] + square[0][3];

    for (int i = 0; i < 4; i++) {
        int rowSum = 0;
        int columnSum = 0;
        for (int j = 0; j < 4; j++) {
            rowSum += square[i][j];
            columnSum += square[j][i];
        }
        // cout << rowSum << "\n" << columnSum << "\n";
        if (rowSum != magicSum || columnSum != magicSum) {
            magic = false;
        }
    }

    if (magic) {
        cout << "magic\n";
    } else {
        cout << "not magic\n";
    }

} 