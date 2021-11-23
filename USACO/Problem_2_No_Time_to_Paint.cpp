#include <bits/stdc++.h>
using namespace std;

int getStrokes(string fences) {
    int strokes = 0;
    char lastChar;
    set<char>::reverse_iterator uniqueLetter; 
    set<char> uniqueLetters(fences.begin(), fences.end());

    for (uniqueLetter = uniqueLetters.rbegin(); uniqueLetter != uniqueLetters.rend(); uniqueLetter++) {
        for (int j = 0; j < fences.size(); j++) {
            char letter = fences[j];

            if (letter == *uniqueLetter) {
                if (letter != lastChar) {
                    strokes++;
                }
                
                fences.erase(fences.begin() + j);
            }

            lastChar = letter;
        }
    }

    return strokes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, Q;
    string fences;
    cin >> N >> Q >> fences;

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        string leftFences = fences.substr(0, a - 1);
        string rightFences = fences.substr(b, fences.size() - b);
        int strokes = getStrokes(leftFences) + getStrokes(rightFences);
        cout << strokes << '\n';
    }
}