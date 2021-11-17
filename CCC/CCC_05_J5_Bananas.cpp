#include <bits/stdc++.h>
using namespace std;

bool isAWord(string word);

bool isMonkeyLanguageWord(string word) {
    if (isAWord(word)) return true;

    for (int nPosition = 0; nPosition < word.length(); nPosition++) {
        if (word[nPosition] != 'N') {
            continue;
        }

        if (word.length() >= 3 && nPosition != string::npos) {
            string beforeN = word.substr(0, nPosition);
            string afterN = word.substr(nPosition + 1, word.length() - nPosition - 1);
            if (beforeN.length() > 0 && afterN.length() > 0 && isAWord(beforeN) && isMonkeyLanguageWord(afterN)) return true;
        }
    }

    return false;
}

bool isAWord(string word) {
    if (word == "A") return true;

    if (word.length() >= 3 && word[0] == 'B' && word[word.length() - 1] == 'S') {
        string substring = word.substr(1, word.length() - 2);
        if (substring.length() > 0 && isMonkeyLanguageWord(substring)) return true;  
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string word;
        getline(cin, word);

        if (word == "X") break;

        cout << (isMonkeyLanguageWord(word) ? "YES\n" : "NO\n");
    }
}