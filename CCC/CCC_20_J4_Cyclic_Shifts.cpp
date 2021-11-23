#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string T, S;
    cin >> T >> S;
    int shifts = S.size();
    string found = "no";

    for (int i = 0; i < shifts; i++) {
        S += S[0];
        S = S.substr(1, shifts);

        if (T.find(S) != string::npos) {
            found = "yes";
            break;
        }
    }

    cout << found;
}