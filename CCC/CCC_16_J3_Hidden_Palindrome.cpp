#include <bits/stdc++.h> 

using namespace std; 

bool isPalindrome (string word) {
    string backwards;
    for (int i = word.size() - 1; i >= 0; i--) {
        backwards += word[i];
    }
    return backwards == word;
}

int main() { 
    string word;
    cin >> word;
    int longest = 0;
    for (int i = 1; i <= word.size(); i++) {
        for (int j = 0; j <= word.size() - i; j++) {
            string substring = word.substr(j, i);
            if (isPalindrome(substring) && substring.size() > longest) {
                longest = substring.size();
            }
        }
    }
    cout << longest;
} 