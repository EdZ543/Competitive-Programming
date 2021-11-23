#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k; cin >> k;
    char letters[k];
    string codes[k];
    for (int i = 0; i < k; i++) cin >> letters[i] >> codes[i];
    string sequence; cin >> sequence;
    int index = 0;
    while (true) {
        for (int i = 0; i < k; i++) {
            if (sequence.size() - index < codes[i].size()) {
                continue;
            }
            string substring = sequence.substr(index, codes[i].size());
            if (substring == codes[i]) {
                cout << letters[i];
                index += codes[i].size(); 
                break;
            }
        }
        if (index >= sequence.size()) {
            break;
        }
    }
}