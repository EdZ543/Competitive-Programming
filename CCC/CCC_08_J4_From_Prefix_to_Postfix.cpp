#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	while (true) {
        string prefix;
        getline(cin, prefix);

        if (prefix == "0") {
            break;
        }

        vector<string> tokens;
        stringstream check1(prefix);
        string intermediate;
        while(getline(check1, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }

        for (size_t i = tokens.size(); i --> 0;) {
            if (tokens[i] == "+" || tokens[i] == "-") {
                tokens[i + 1] += " " + tokens[i + 2] + " " + tokens[i];
                tokens.erase(tokens.begin() + i);
                tokens.erase(tokens.begin() + i + 1);
                i = tokens.size();
            }
        }

        for (string token : tokens) {
            cout << token;
        }

        cout << "\n";
    }
}