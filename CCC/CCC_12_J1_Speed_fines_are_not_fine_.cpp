#include <bits/stdc++.h>

using namespace std;

int main() {
    int limit;
    int speed;
    cin >> limit;
    cin >> speed;

    if (speed > limit && speed <= limit + 20) {
        cout << "You are speeding and your fine is $100.";
    } else if (speed > limit + 20 && speed <= limit + 30) {
        cout << "You are speeding and your fine is $270.";
    } else if (speed > limit + 30) {
        cout << "You are speeding and your fine is $500.";
    } else {
        cout << "Congratulations, you are within the speed limit!";
    }
}