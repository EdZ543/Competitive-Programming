#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string keyword, decodedMessage, encodedMessage;
    getline(cin, keyword);
    getline(cin, decodedMessage);
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> keywordShifts;

    for (char c : keyword) {
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), c);
        if(it != alphabet.end()) {
            int index = distance(alphabet.begin(), it);
            keywordShifts.push_back(index);
        }
    }

    for (char c : decodedMessage) {
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), c);
        if(it != alphabet.end()) {
            encodedMessage += c;
        }
    }

    for (int i = 0; i < encodedMessage.size(); i++) {
        int keywordIndex = i % keywordShifts.size();
        int keywordShift = keywordShifts[keywordIndex];
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), encodedMessage[i]);
        if(it != alphabet.end()) {
            int index = distance(alphabet.begin(), it);
            encodedMessage[i] = alphabet[(index + keywordShift) % 26];
        }
    }

    cout << encodedMessage;
}