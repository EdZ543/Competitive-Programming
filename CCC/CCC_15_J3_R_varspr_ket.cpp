#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    string word;
    cin >> word;
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < word.size(); i++) {
        cout << word[i];
        if (find(consonants.begin(), consonants.end(), word[i]) != consonants.end()) {
            int alphabetIndex;
            vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), word[i]);
            if(it != alphabet.end()) {
                alphabetIndex = distance(alphabet.begin(), it);
            }
            int leftVowelIndex = alphabetIndex;
            int rightVowelIndex = alphabetIndex;
            int leftVowelDistance = 0;
            int rightVowelDistance = 0;
            while (find(vowels.begin(), vowels.end(), alphabet[leftVowelIndex]) == vowels.end()) {
                leftVowelIndex--;
                leftVowelDistance++;
            }
            while (find(vowels.begin(), vowels.end(), alphabet[rightVowelIndex]) == vowels.end()) {
                rightVowelIndex++;
                rightVowelDistance++;
            }
            if (rightVowelDistance < leftVowelDistance) {
                cout << alphabet[rightVowelIndex];
            } else {
                cout << alphabet[leftVowelIndex];
            }
            if (word[i] == 'z') {
                cout << 'z';
            } else {
                vector<char>::iterator it = find(consonants.begin(), consonants.end(), word[i]);
                if(it != consonants.end()) {
                    int consonantsIndex = distance(consonants.begin(), it);
                    cout << consonants[consonantsIndex + 1];
                }
            }
        }
    }  
} 