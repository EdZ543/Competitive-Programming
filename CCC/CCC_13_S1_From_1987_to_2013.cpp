#include <bits/stdc++.h>
using namespace std;

bool distinct(int x) {
    string str = to_string(x);
    for (int i = 0; i < str.size(); i++) {
        string pastChars = str.substr(0, i);
        if (pastChars.find(str[i]) != string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Y; cin >> Y;
    do {
        Y++;
    }
    while (!distinct(Y));
    cout << Y;
}