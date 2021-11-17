#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    while (true) {
        string word;
        cin >> word;
        
        if (word == "halt") {
            break;
        }

        int time = 0;
        // vector<char> onePress = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
        // vector<char> twoPress = {'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x'};
        // vector<char> threePress = {'c', 'f', 'i', 'l', 'o', 'r', 'v', 'y'};
        // vector<char> fourPress = {'s', 'z'};
        vector<vector<char>> keys = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

        for (int i = 0; i < word.size(); i++) {
            // if (find(onePress.begin(), onePress.end(), word[i]) != onePress.end()) {
            //     time++;
            // } else if (find(twoPress.begin(), twoPress.end(), word[i]) != twoPress.end()) {
            //     time += 2;
            // } else if (find(threePress.begin(), threePress.end(), word[i]) != threePress.end()) {
            //     time += 3;
            // } else if (find(fourPress.begin(), fourPress.end(), word[i]) != fourPress.end()) {
            //     time += 4;
            // }
            vector<char> button;

            for (auto const &stringVector : keys) {
                auto it = find(begin(stringVector), end(stringVector), word[i]);
                if (it != end(stringVector)) {
                    time += distance(stringVector.begin(), it) + 1;
                    button = stringVector;
                    break;
                }
            }

            if (find(button.begin(), button.end(), word[i + 1]) != button.end()) {
                time += 2;
            }
        }

        cout << time << "\n";
    }
} 