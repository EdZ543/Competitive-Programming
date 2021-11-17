#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string word, anagram;
    getline(cin, word);
    getline(cin, anagram);

    word.erase(remove(word.begin(), word.end(), ' '), word.end()); 
    anagram.erase(remove(anagram.begin(), anagram.end(), ' '), anagram.end()); 

    if (word.size() != anagram.size()) {
        cout << "Is not an anagram.";
        return 0;
    }

    string toRemove = word;

    for (char c : toRemove) {
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == c) {
                word.erase(word.begin() + i);
                break;
            }
        }
        for (size_t i = 0; i < anagram.size(); i++) {
            if (anagram[i] == c) {
                anagram.erase(anagram.begin() + i);
                break;
            }
        } 
    }
    string result = (word == "" && anagram == "") ? "Is an anagram." : "Is not an anagram.";
    cout << result;
}