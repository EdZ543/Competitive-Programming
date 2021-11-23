#include <bits/stdc++.h>

using namespace std;

int main() {
    int S;
    int M;
    int L;
    cin >> S;
    cin >> M;
    cin >> L;
    int happiness = 1 * S+2 * M+3 * L;
    if (happiness >= 10) {
        cout << "happy";
    } else {
        cout << "sad";
    }
}