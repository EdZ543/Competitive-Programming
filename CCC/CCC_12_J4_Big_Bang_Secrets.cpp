#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int K;
    string encoded;
    cin >> K >> encoded;
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < encoded.size(); i++) {
        char c = encoded[i];
        int pos;
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), c);
        if (it != alphabet.end()) {
            pos = distance(alphabet.begin(), it);
        }

        int S = 3 * (i + 1) + K;
        pos -= S;

        if (pos < 0) {
            pos = 26 - abs(pos);
        }

        cout << alphabet[pos];
    }
}