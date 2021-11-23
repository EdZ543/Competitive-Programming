#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int min, max;
    cin >> min >> max;

    int totalRotatable = 0;

    for (int i = min; i < max + 1; i++) {
        string regularNum = to_string(i);
        string flippedNum = "";

        for (char c : regularNum) {
            switch(c) {
                case '0':
                    flippedNum += '0';
                    break;
                case '1':
                    flippedNum += '1';
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                case '5':
                    break;
                case '6':
                    flippedNum += '9';
                    break;
                case '7':
                    break;
                case '8':
                    flippedNum += '8';
                    break;
                case '9':
                    flippedNum += '6';
                    break;
            }
        }

        reverse(flippedNum.begin(), flippedNum.end()); 

        if (regularNum == flippedNum && flippedNum[0] != '0') {
            // cout << regularNum << "\n";
            totalRotatable++;
        }
    }

    cout << totalRotatable;
} 