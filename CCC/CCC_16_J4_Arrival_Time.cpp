#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string departTime;
    cin >> departTime;
    vector<string> tokens;
    stringstream check1(departTime);
    string intermediate;
    while(getline(check1, intermediate, ':')) {
        tokens.push_back(intermediate);
    }
    int h = stoi(tokens[0]);
    int m = stoi(tokens[1]);

    for (int i = 0; i < 120; i++) {
        bool rushHour = false;

        if (h >= 7 && h <= 9) {
            rushHour = true;
        }

        if (h >= 15 && h <= 18) {
            rushHour = true;
        }

        if (rushHour) {
            m += 2;
        } else {
            m++;
        }

        if (m >= 60) {
            m -= 60;
            h++;
        }

        if (h >= 24) {
            h -= 24;
        }
    }

    string h2 = string(2 - to_string(h).length(), '0') + to_string(h);
    string m2 = string(2 - to_string(m).length(), '0') + to_string(m);

    cout << h2 << ":" << m2;
}