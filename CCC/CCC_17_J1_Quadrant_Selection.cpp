#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    int y;
    cin >> x;
    cin >> y;
    if (x > 0) {
        if (y > 0) {
            cout << "1";
        } else if (y < 0) {
            cout << "4";
        }
    } else if (x < 0) {
        if (y > 0) {
            cout << "2";
        } else if (y < 0) {
            cout << "3";
        }
    }
}