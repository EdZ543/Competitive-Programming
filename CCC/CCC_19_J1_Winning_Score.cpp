#include <bits/stdc++.h>

using namespace std;

int main() {
    int A3;
    int A2;
    int A1;
    int B3;
    int B2;
    int B1;
    cin >> A3;
    cin >> A2;
    cin >> A1;
    cin >> B3;
    cin >> B2;
    cin >> B1;
    int A = (3 * A3) + (2 * A2) + A1;
    int B = (3 * B3) + (2 * B2) + B1;
    if (A > B) {
        cout << "A";
    } else if (A < B) {
        cout << "B";
    } else if (A == B) {
        cout << "T";
    }
}