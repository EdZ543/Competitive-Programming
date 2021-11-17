#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    while (true) {
        string word;
        cin >> word;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

        if (word == "quit!") {
            break;
        }

        if (word.size() > 4 && 
        word.at(word.size() - 1) == 'r' &&
        word.at(word.size() - 2) == 'o' &&
        std::find(vowels.begin(), vowels.end(), word.at(word.size() - 3)) == vowels.end()) {
            word.at(word.size() - 1) = 'u';
            word += 'r';
        }

        cout << word << "\n";
    }
} 