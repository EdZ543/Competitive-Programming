#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    string text;
    getline(cin, text);
    int numHappy = 0;
    int numSad = 0;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ':' && text[i+1] == '-') {
            if (text[i+2] == ')') {
                numHappy++;
            }
            if (text[i+2] == '(') {
                numSad++;
            }
        }
    }

    if (numHappy == 0 && numSad == 0) {
        cout << "none";
    } else if (numHappy == numSad) {
        cout << "unsure";
    } else if (numHappy > numSad) {
        cout << "happy";
    } else if (numSad > numHappy) {
        cout << "sad";
    }
} 