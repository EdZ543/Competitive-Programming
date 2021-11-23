#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    string word;
    getline (cin, word);
    vector<vector<char>> keys = {      
        {'A',	'B',	'C',	'D',	'E',	'F'},
        {'G',	'H',	'I',	'J',	'K',	'L'},
        {'M',	'N',	'O',	'P',	'Q',	'R'},
        {'S',	'T',	'U',	'V',	'W',	'X'},
        {'Y',	'Z',	' ',	'-',	'.',	'!'},
    };

    int x = 0;
    int y = 0;
    int total = 0;
    for (char c : word) {
        int cX;
        int cY;
        for (int i = 0; i < keys.size(); i++) {
            for (int j = 0; j < keys[i].size(); j++) {
                if (keys[i][j] == c) {
                    cX = j;
                    cY = i;
                    break;
                }
            }
        }
        total += abs(cX - x);
        total += abs(cY - y);
        x = cX;
        y = cY;
    }
    total += abs(5 - x);
    total += abs(4 - y);
    cout << total;
} 