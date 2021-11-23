#include <bits/stdc++.h>

using namespace std;

int main() {
    int digits[4];
    for (int x = 0; x < 4; x++) {
        cin >> digits[x];
    }

    if ((digits[0] == 8 || digits[0] == 9) &&
    (digits[3] == 8 || digits[3] == 9) &&
    (digits[1] == digits[2])) {
        cout << "ignore";
    } else {
        cout << "answer";
    }
}