#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;
    vector<string> encodedLines;

    for (int i = 0; i < N * 2; i++) {
        string encodedLine;
        cin >> encodedLine;
        encodedLines.push_back(encodedLine);
    }

    for (int i = 0; i < N * 2; i += 2) {
        string decodedLine = "";
        for (int j = 0; j < stoi(encodedLines[i]); j++) {
            decodedLine += encodedLines[i + 1];
        }
        cout << decodedLine << "\n";
    }
} 