#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        string newLine;

        char pastC = line[0];
        int times = 0;
        for (char c : line) {
            if (c != pastC) {
                newLine += to_string(times) + ' ' +  pastC + ' ';
                pastC = c;
                times = 1;
            } else {
                times++;
            }
        }
        newLine += to_string(times) + ' ' +  pastC + ' ';
        cout << newLine << "\n";
    }
} 