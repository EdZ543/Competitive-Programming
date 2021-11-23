#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int left = 0;
    int right = 0;
    int output = 0;

    if (n <= 5) {
        left = n;
    }
    if (n > 5) {
        left = 5;
        right = n-5;
    }

    while (left >= right && left <= 10 && right <= 10) {
        output++;
        left--;
        right++;
    }

    cout << output;
}