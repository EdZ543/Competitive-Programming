#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    cin.ignore();
    for (int n = 0; n < N; n++) {
        vector<string> rhymes(4);
        for (int i = 0; i < 4; i++) {
            string line; getline(cin, line);
            int index = line.size();
            while (true) {
                index--;
                char lower = tolower(line[index]);
                if (
                index == 0
                || lower == 'a'
                || lower == 'e'
                || lower == 'i'
                || lower == 'o'
                || lower == 'u'
                || line[index-1] == ' ') {
                    string rhyme = line.substr(index, line.size()-index);
                    transform(begin(rhyme), end(rhyme), begin(rhyme), ::tolower);
                    rhymes[i] = rhyme;
                    break;
                }
            }
        }
        if (rhymes[0] == rhymes[1]
        && rhymes[1] == rhymes[2]
        && rhymes[2] == rhymes[3]) {
            cout << "perfect\n";
        } else if (rhymes[0] == rhymes[1]
        && rhymes[2] == rhymes[3]) {
            cout << "even\n";
        } else if (rhymes[0] == rhymes[2]
        && rhymes[1] == rhymes[3]) {
            cout << "cross\n";
        } else if (rhymes[0] == rhymes[3]
        && rhymes[1] == rhymes[2]) {
            cout << "shell\n";
        } else {
            cout << "free\n";
        }
    }
}