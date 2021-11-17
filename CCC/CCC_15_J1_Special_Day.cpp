#include <bits/stdc++.h>

using namespace std;

int main() {
    int month;
    int day;
    cin >> month;
    cin >> day;

    if (month < 2) {
        cout << "Before";
    } else if (month > 2) {
        cout << "After";
    } else if (month == 2) {
        if (day < 18) {
            cout << "Before";
        } else if (day > 18) {
            cout << "After";
        } else if (day == 18) {
            cout << "Special";
        }
    }
}